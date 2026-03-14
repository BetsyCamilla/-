
①说明：参照王馨（2021）的做法，本团队对来自管理世界《绿色信贷政策增进绿色创新研究》一文中的基准回归部分进行复刻。
②注：内含原始数据、处理代码、回归结果
③步骤：1、导入原始数据、控制变量；2、数据对数处理、单位转换；3、使用面板数据，进行基准回归。
*/


**************************一、定义数据**************************
*导入数据
cd F:\绿色信贷政策增进绿色创新研究
use macrodata_basic,clear


* DID变量
gen Policy =0
gen Gcres = 0 
replace Policy=1 if 年份>=2012
replace Gcres =1 if 绿色信贷_环境和社会风险类型=="A"  //| 绿色信贷_环境和社会风险类型=="B"
gen DID= Policy*Gcres


*处理控制变量
rename (绿色专利申请量 绿色发明专利申请量 绿色实用新型专利申请量 机构投资者持股比例 两职合一 独立董事占比 所有者权益占市值之比 现金占总资产之比  资产负债率  固定资产总额占总资产之比 总资产收益率 员工人数_个 托宾Q值) (绿色专利申请 绿色发明申请 绿色实用新型申请 机构投资持股 两职合一 独立董事占比 账面市值比 现金比例 资产负债率  固定资产比例 总资产收益率 员工规模 托宾Q值)

global depend_var "绿色专利申请 绿色发明申请 绿色实用新型申请"

global independ_var "DID"

global kongzhi_var "Policy Gcres 机构投资持股 两职合一 独立董事占比 账面市值比 现金比例 资产负债率  固定资产比例 总资产收益率 员工规模 托宾Q值" 

*定义需要对数处理的变量
global ln_var  "绿色专利申请 绿色发明申请 绿色实用新型申请 员工规模"

*定义需要缩尾处理的变量
global ss_var  "机构投资持股 两职合一 独立董事占比 账面市值比 现金比例 资产负债率 固定资产比例 总资产收益率 员工规模 托宾Q值"

*定义需要平方处理的变量
global sq_var  ""

*定义需要标准化处理的变量
global stand_var ""


**************************二、数据处理**************************
*保存所需数据
keep if 年份 >= 2007 & 年份 <= 2020
drop if substr(行业代码,1,1) =="J"

* 删除缺失值
egen mis=rowmiss($depend_var $independ_var $kongzhi_var)
drop if mis

*对数处理
foreach v in $ln_var{
	replace `v' = ln(`v'+1)
}

*平方处理
foreach v in $sq_var{
	gen `v'的平方 = `v' * `v'
}

*标准化处理
foreach v in $stand_var{
	qui sum `v'
	replace `v'=(`v'-r(mean))/r(sd) 
}

*缩尾处理
foreach v in $ss_var{
	winsor2 `v', replace cuts(1 99)
}

*将数据设置为面板格式
xtset 股票代码 年份
encode 行业代码,gen(industry_code)
encode 所属省份,gen(prov_code)


**************************三、描述性统计**************************
sum $depend_var $independ_var $kongzhi_var


**************************四、基准回归**************************
* 基本回归分析
local i = 1
local j = 1
foreach v1 in $depend_var {
	local j = 1
	foreach v2 in $independ_var{
		qui xtreg `v1' `v2' ,fe cluster(股票代码)
		est store _m1_`i'_`j'
		qui xtreg `v1' `v2' $kongzhi_var i.年份 i.prov_code,fe cluster(股票代码)
		est store _m2_`i'_`j'
		qui xtreg `v1' `v2' $kongzhi_var i.年份 i.prov_code i.industry_code,fe cluster(股票代码)
		est store _m3_`i'_`j'
		local j = `j'+1
	}
	local i = `i'+1
}

esttab _m* , b(%8.3f) t(%8.3f) mtitles()  star(* 0.1 ** 0.05 *** 0.01) drop( *prov* *industry* *年份*)  order($independ_var) compress






