********************************************************************************
*===============《"安居"方能"乐业"：租赁住房供给与稳就业》=====================*
*******************************************************************************
*=========================使用软件Stata/MP 17.0================================*
use data2,clear
xtset id year

global con "perr size sale dual re ppe roa lrgdp gexp gdeposit"
global con1 "perr size sale dual re ppe roa gexp gdeposit second lrgdp gfdi lprice lwage_ave"
global cont1 "densize denpop roa lev dual"
global cont2 "densize_dsale denpop_dsale roa_dsale lev_dsale dual_dsale"
global cont3 "dec_densize_dsale dec_denpop_dsale dec_roa_dsale dec_dual_dsale dec_lev_dsale"

*=======表2 基准回归：租赁住房扩张与微观就业规模===============================*
areg pop did  i.year i.industry      ,a(id) cl(id)
est store m1  //第1列
areg pop did $con i.year i.industry  ,a(id) cl(id)
est store m2  //第2列
areg pop did $con  i.year i.industry i.year#i.industry  ,a(id) cl(id)
est store m3  //第3列
areg pop did $con  i.year i.industry c.year#i.industry  ,a(id) cl(id)
est store m4  //第4列
 
esttab m1 m2 m3 m4 using 表2基准回归：租赁住房扩张与微观就业规模.rtf ,keep(did) replace b(%6.4f) se(%6.4f) ar2(3) star(* 0.1 ** 0.05 *** 0.01) compress nogap

*========表3 机制检验：劳动力供求分析==========================================*
areg wagepop did $con  i.year i.industry   ,a(id) cl(id)
est store m1  //第1列
areg costpop did $con  i.year i.industry   ,a(id) cl(id)
est store m2  //第2列
areg mancost did $con  i.year i.industry   ,a(id) cl(id)
est store m3  //第3列
areg wrent_wage did $con i.year i.industry ,a(id) cl(id)
est store m4  //第4列
areg rent_cost did $con  i.year i.industry ,a(id) cl(id)
est store m5  //第5列
areg wagepop1 did $con  i.year i.industry  ,a(id) cl(id)
est store m6  //第6列
areg costpop1 did $con  i.year i.industry  ,a(id) cl(id)
est store m7  //第7列

esttab m1 m2 m3 m4 m5 m6 m7 using 表3机制检验：劳动力供求分析.rtf ,keep(did) replace b(%6.4f) se(%6.4f) ar2(3) star(* 0.1 ** 0.05 *** 0.01) compress nogap

*=========表4 溢出效应：异地就业效应检验=======================================*
areg pop did nbr_did $con i.year i.industry ,a(id) cl(year_prov)
est store m1  //第1列
areg pop did nbr_did $con i.year i.industry if treat==0,a(id) cl(year_prov)
est store m2  //第2列
areg pop did distance $con i.year i.industry ,a(id) cl(year_prov) 
est store m3  //第3列
areg pop did distance $con i.year i.industry if treat==0,a(id) cl(year_prov) 
est store m4  //第4列

esttab m1 m2 m3 m4 using 表4溢出效应：异地就业效应检验.rtf ,keep(did nbr_did distance) replace b(%6.4f) se(%6.4f) ar2(3) star(* 0.1 ** 0.05 *** 0.01) compress nogap

*==========表5  异质性分析=====================================================*
areg pop did $con i.year i.industry if d1==1 ,a(id) cl(id)
est store m1  //第1列
areg pop did $con i.year i.industry if d1==0 ,a(id) cl(id)
est store m2  //第2列
areg pop did $con i.year i.industry if d2==1 ,a(id) cl(id)
est store m3  //第3列
areg pop did $con i.year i.industry if d2==0 ,a(id) cl(id)
est store m4  //第4列
areg pop did $con i.year i.industry if d3==1 ,a(id) cl(id)
est store m5  //第5列
areg pop did $con i.year i.industry if d3==0 ,a(id) cl(id)
est store m6  //第6列
areg pop did $con i.year i.industry if d4==1 ,a(id) cl(id)
est store m7  //第7列
areg pop did $con i.year i.industry if d4==0 ,a(id) cl(id)
est store m8  //第8列
areg pop did $con i.year i.industry if d5==1 ,a(id) cl(id)
est store m9  //第9列
areg pop did $con i.year i.industry if d5==0 ,a(id) cl(id)
est store m10  //第10列
areg pop did $con i.year i.industry if d6==1 ,a(id) cl(id)
est store m11  //第11列
areg pop did $con i.year i.industry if d6==0 ,a(id) cl(id)
est store m12  //第12列

esttab m1 m2 m3 m4 m5 m6 m7 m8 m9 m10 m11 m12 using 表5异质性分析.rtf ,keep(did) replace b(%6.4f) se(%6.4f) ar2(3) star(* 0.1 ** 0.05 *** 0.01) compress nogap

*===========表6 滞后效应分析===================================================*
order id year
areg pop L.did L.perr L.size L.dual L.re L.ppe L.roa L.sale L.lrgdp L.gexp L.gdeposit i.year i.industry  ,a(id) cl(id)
est sto m1  //第1列
areg F.pop did $con i.year i.industry   ,a(id) cl(id)
est sto m2  //第2列
areg pop did_un $con i.year i.industry   ,a(id) cl(id)
est sto m3  //第3列
areg pop L.did_un L.perr L.size L.dual L.re L.ppe L.roa L.sale L.lrgdp L.gexp L.gdeposit i.year i.industry  ,a(id) cl(id)
est sto m4  //第4列				 
areg F.pop did_un $con i.year i.industry   ,a(id) cl(id)
est sto m5  //第5列

esttab m1 m2 m3 m4 m5 using 表6滞后效应分析.rtf ,keep(L.did did did_un L.did_un) replace b(%6.4f) se(%6.4f) ar2(3) star(* 0.1 ** 0.05 *** 0.01) compress nogap

*============图2 事前平行趋势检验==============================================*
areg pop pre4 pre3 pre2 post0 post1 post2 post3 post4 pre1 $con i.year i.industry i.year#i.industry,a(id) cl(id)
//事前联合系数检验
test pre4+pre3+pre2+pre1=0
test post0+post1+post2+post3+post4=0
//绘图
coefplot, baselevels keep(pre* current post*) order(pre4 pre3 pre2 pre1 post0 post1 post2 post3 post4) omitted vertical coeflabels( pre4="-4" pre3 = "-3" pre2 = "-2" pre1 = "-1" post0 = "0" post1 = "1" post2 = "2" post3 = "3" post4 = "4") yline(0,lcolor(edkblue*0.8)) ylabel(-0.1(0.05)0.15) xline(10, lwidth(vthin) lpattern(dash) lcolor(teal)) ylabel(,labsize(*0.75)) xlabel(,labsize(*0.75)) level(90) legend(label(1 `"90%{fontface "宋体":置信区间}"') label(2 `"{fontface "宋体": 估计系数}"') rows(1) order(1 2) ) ytitle("政策动态经济效应", size(small)) xtitle("政策时点", size(small)) addplot(line @b @at) ciopts(lpattern(dash) recast(rcap) msize(medium)) msymbol(circle_hollow) scheme(s1mono)

*============图3 安慰剂检验====================================================*
/*以下为安慰剂检验3000次随机试验的循环命令，运行时间比较长，为节省您的时间，我们已在附件直接提供该命令得到的数据集"安慰剂检验.dta"，可以直接从下面的绘图命令开始运行。
mat b = J(3000,1,0)
mat se = J(3000,1,0)
mat p = J(3000,1,0)
set seed 10101
forvalues i = 1/3000{
      
	  use data2,clear   
	  xtset id year
	  sample 1 ,count by(id)
	  sample 1008 ,count 
	  keep id year 
	  rename year matchyear
	  save matchyear, replace
	  merge 1:m id using data2
	  xtset id year
	  gen falsetreat=(_merge==3)
	  gen falsepost=(year>=matchyear)
	  gen falseDID=falsetreat*falsepost
	  global con "perr size dual re ppe roa sale lrgdp gexp gdeposit"
	  areg pop falseDID  $con i.year i.industry,a(id) cl(id)
	
	mat b[`i',1] = _b[falseDID]
	mat se[`i',1] = _se[falseDID]
	scalar df_r = e(N) - e(df_m) -1
	mat p[`i',1] = 2*ttail(df_r,abs(_b[falseDID]/_se[falseDID]))
}
svmat b, names(coef)
svmat se, names(se)
svmat p, names(pvalue)
drop if pvalue1 == .
label var pvalue1 p值
label var coef1 估计系数
keep coef1 se1 pvalue1 
save 安慰剂检验,replace
*/

//绘图：可从这里直接运行
use 安慰剂检验,clear
twoway (kdensity coef1,yaxis(2) color(black)) (scatter pvalue1 coef1, msymbol(smcircle_hollow) mcolor(black)), xlabel(-0.07(0.035)0.07 0.0585) ylabel(0(3)24,axis(2)) ylabel(0(0.2)1 0.1,axis(1))  xline(0.0585, lwidth(vthin) lp(shortdash)) xtitle("系数值") yline(0.1,lwidth(vthin) lp(dash)) ytitle("p""值",orientation(horizontal)size(*0.8)) ylabel(, nogrid format(%4.1f) labsize(small)) ytitle("核""密""度" ,orientation(horizontal)  size(*0.8) axis(2)) ylabel(, nogrid format(%4.1f) labsize(small) axis(2)) legend(label(1 "核密度") label( 2 "p值")) graphregion(color(white)) 

*========表7 异质性稳健DID估计检验=============================================*
use data2,clear
xtset id year

//Chaisemartin和D'Haultfoeuille（2020）权重分解
twowayfeweights pop id year did industry, controls( $con ) type(feTR)  //第1列

//Goodman-Bacon（2021）权重分解
ddtiming pop did ,i(id) t(year)  //第2列：ddtiming是外部命令，无法直接ssc在线安装。我们在附件中提供了作者电脑上运行该命令的结果截图。

//两阶段双重差分模型（did2s）回归
did2s pop  ,first_stage(id year industry $con ) second_stage(did) treatment(did) cluster(id)  //第3列

//Goodman-Bacon（2021）回归
xtbalance, range(2010 2021) miss(pop did $con) //该命令必须使用平衡面板
bacondecomp pop did $con , ddetail  //第4列：bacondecomp是外部命令，无法直接ssc在线安装。我们在附件中提供了作者电脑上运行该命令的结果截图。

*=========表8 排除不同群组间的系统性差异=======================================*
use data2,clear
xtset id year

psmatch2 treat perr size roa re dual ppe sale ,outcome (pop) logit neighbor(2)  ties ate common odds
areg pop did $con i.year i.industry  if _weight!=.   ,a(id) cl(id)
est store m1  //第1列
ebalance treat perr size roa re dual ppe sale , targets(3) keep(baltable) replace 
areg pop did $con i.year i.industry [pweight=_webal] ,a(id) cl(id)
est store m2  //第2列
areg pop did $con i.year i.industry if indus_1!="K"&indus_1!="E" ,a(id) cl(id)
est store m3  //第3列
reghdfe pop did $con , a(id year industry i.industry#i.year i.industry#i.tt) cl(id)
est store m4  //第4列
areg pop did $con  i.year i.industry if citydiff==1 ,a(id) cl(id)
est store m5  //第5列
areg pop did $con  i.year i.industry if netflow_m>=0  ,a(id) cl(id)
est store m6  //第6列
areg pop did $con i.year i.industry if city!=1100&city!=3100 ,a(id) cl(id)
est store m8  //第8列
areg pop did $con i.year i.industry if year>=2012 ,a(id) cl(id)
est store m9  //第9列
areg pop did $con i.year i.industry if treat2019==0 ,a(id) cl(id)
est store m10  //第10列

esttab m1 m2 m3 m4 m5 m6 m8 m9 m10 using 表8排除不同群组间的系统性差异.rtf ,keep(did) replace b(%6.4f) se(%6.4f) ar2(3) star(* 0.1 ** 0.05 *** 0.01) compress nogap

use data3,clear //包含深圳的样本，需要重设一遍控制变量的集合
areg pop did $con i.year i.industry ,a(id) cl(id)
est sto m7   //第7列

esttab m7 using 表8排除不同群组间的系统性差异第7列.rtf ,keep(did) replace b(%6.4f) se(%6.4f) ar2(3) star(* 0.1 ** 0.05 *** 0.01) compress nogap

*============表9 进一步分析：劳动力配置效率与成本刚性==========================*
use data2,clear
xtset id year

areg epop did  $con i.year i.industry if epop>=0 ,a(id) cl(id)
est store m1  //第1列
areg epop did  $con i.year i.industry if epop<0 ,a(id) cl(id)
est store m2  //第2列
areg dcost dec_did_dsale dec_dsale did_dsale dec_did did dsale dec $cont1 $cont2 $cont3 i.year i.industry  ,a(id) cl(id)
est store m3  //第3列
sort id year
areg F2.dcost dec_did_dsale did_dsale dec_did did dec_dsale dsale dec $cont1 $cont2 $cont3 i.year i.industry   ,a(id) cl(id)
est store m4  //第4列

esttab m1 m2 m3 m4 using 表9进一步分析：劳动力配置效率与成本刚性.rtf ,keep( dec_did_dsale did ) replace b(%6.4f) se(%6.4f) ar2(3) star(* 0.1 ** 0.05 *** 0.01) compress nogap

*=============附表2 主要变量定义与描述性统计——企业层面变量=====================*
sum did pop perr size sale dual re ppe roa
sum2docx did pop perr size sale dual re ppe roa using 附表2企业层面主要变量定义与描述性统计.docx,replace stats (N mean(%9.4f) sd(%9.4f) min(%9.4f) max(%9.4f)) title("附表2主要变量定义与描述性统计")

*=============附图3 就业溢出效应的辐射范围=====================================*
areg pop did dis45 dis90 dis135 dis180 dis270 dis315 dis360 dis405 $con i.year i.industry,a(id) cl(year_prov)
parmest, saving("溢出效应距离1.dta", replace)
use "溢出效应距离1.dta",clear
keep if ustrregexm(parm,"dis")
set obs 9
replace parm = "dis225" in 9
gen id=_n*45
replace id=id+45 if id>180&id<405
replace id=225 if parm == "dis225"
sort id
 gen u1=estimate+stderr*1.65
 gen l1=estimate-stderr*1.65
 for var estimate u1  l1 :replace X= 0 if mi(t)
  graph twoway (rcap l1 u1 id  ,lcolor(black) mcolor(black) msymbol(O) mlabcolor(black))|| (scatter estimate id, mcolor(black) msymbol(O) mlabcolor(black)) || (line estimate id,lcolor(black)) , yline(0,  lcolor(black))  legend(label(1 `"90%{fontface "宋体":置信区间}"') label(2 `"{fontface "宋体": 估计系数}"') rows(1) order(1 2) ) ytitle(`"{fontface "宋体":政策溢出效应}"') xtitle(`"{fontface "宋体":到试点城市距离（千米）}"') xlabel(45(45)405)scheme(s1mono) graphregion(fcolor(gs16) lcolor(gs16)) plotregion(lcolor("white"))

*=============附表5 排除潜在的遗漏变量=========================================*
use data2,clear
xtset id year

areg pop did $con fsupply fdemand growth_house  i.year i.industry ,a(id) cl(id)
est store m1  //第1列
areg pop did c.year#c.rjqperr c.year#c.rjqsize c.year#c.rjqroa c.year#c.rjqre c.year#c.rjqppe c.year#c.rjqsale c.year#c.rjqdual lrgdp gexp gdeposit i.year i.industry ,a(id) cl(id)
est store m2  //第2列
areg pop before1 did $con i.year i.industry    ,a(id) cl(id)
est store m3  //第3列
areg pop before2 did $con i.year i.industry    ,a(id) cl(id)
est store m4  //第4列
areg pop did $con i.year i.industry if year<2020 ,a(id) cl(id)
est store m5  //第5列

esttab m1 m2 m3 m4 m5 using 附表5排除潜在的遗漏变量.rtf ,keep( before1 before2 did) replace b(%6.4f) se(%6.4f) ar2(3) star(* 0.1 ** 0.05 *** 0.01) compress nogap

*=============附表6 排除其他并行政策的替代性解释===============================*
areg pop did landdid $con i.year i.industry ,a(id) cl(id)
est store m1  //第1列
areg pop did bankdid $con i.year i.industry  ,a(id) cl(id)
est store m2  //第2列
areg pop did house_loan2016 $con  i.year i.industry ,a(id) cl(id)
est store m3  //第3列
areg pop did centredid $con i.year i.industry ,a(id) cl(id)
est store m4  //第4列
areg pop did vatdown $con i.year i.industry  ,a(id) cl(id)
est store m5  //第5列
areg pop did survat $con i.year i.industry ,a(id) cl(id)
est store m6  //第6列
areg pop did acdep $con i.year i.industry ,a(id) cl(id)
est store m7  //第7列
areg pop did fgf  $con i.year i.industry ,a(id) cl(id)
est store m8  //第8列

esttab m1 m2 m3 m4 m5 m6 m7 m8 using 附表6排除其他并行政策的替代性解释.rtf ,keep(did) replace b(%6.4f) se(%6.4f) ar2(3) star(* 0.1 ** 0.05 *** 0.01) compress nogap

*=============附表7 排除内生性：控制宏观前定变量===============================*
areg pop did perr size roa re ppe sale dual t1 t2 t3 i.year i.industry ,a(id) cl(id)
est sto m1  //第1列
areg pop did perr size roa re ppe sale dual t1 t2 t3 tt1 tt2 tt3 i.year i.industry ,a(id) cl(id)
est sto m2  //第2列
areg pop did perr size roa re ppe sale dual t1 t2 t3 tt1 tt2 tt3 ttt1 ttt2 ttt3 i.year i.industry ,a(id) cl(id)
est sto m3  //第3列
areg pop did perr size roa re ppe sale dual i.year#c.rjqlrgdp i.year#c.rjqgexp i.year#c.rjqgdeposit i.year i.industry ,a(id) cl(id)
est sto m4  //第4列
areg pop did perr size roa re ppe sale dual mt1 mt2 mt3 i.year i.industry ,a(id) cl(id)
est sto m5  //第5列
areg pop did perr size roa re ppe sale dual mt1 mt2 mt3 mtt1 mtt2 mtt3 i.year i.industry ,a(id) cl(id)
est sto m6  //第6列
areg pop did perr size roa re ppe sale dual mt1 mt2 mt3 mtt1 mtt2 mtt3 mttt1 mttt2 mttt3 i.year i.industry ,a(id) cl(id)
est sto m7  //第7列
areg pop did perr size roa re ppe sale dual i.year#c.lrgdp3m i.year#c.gexp3m i.year#c.gdeposit3m i.year i.industry ,a(id) cl(id)
est sto m8  //第8列

esttab m1 m2 m3 m4 m5 m6 m7 m8 using 附表7排除内生性：控制宏观前定变量.rtf ,keep( did ) replace b(%6.4f) se(%6.4f) ar2(3) star(* 0.1 ** 0.05 *** 0.01) compress nogap

*=============附表8 排除内生性：基于宏观变量的PSM-DID检验======================*
//面板数据PSM
psmatch2 treat lrgdp gexp gdeposit ,outcome (pop) logit kernel ties ate common odds
areg pop did  i.year i.industry  if _weight!=. ,a(id) cl(id)
est sto m1  //第1列
areg pop did $con i.year i.industry  if _weight!=. ,a(id) cl(id)
est sto m2  //第2列

esttab m1 m2 using 附表8排除内生性1：基于宏观变量的PSM-DID检验.rtf ,keep(did) replace b(%6.4f) se(%6.4f) ar2(3) star(* 0.1 ** 0.05 *** 0.01) compress nogap

//截面数据逐年PSM
use data4,clear //逐年匹配完成样本
global con "perr size sale dual re ppe roa lrgdp gexp gdeposit"
areg pop did  i.year i.industry  if _weight!=. ,a(id) cl(id)
est sto m3  //第3列
areg pop did $con i.year i.industry  if _weight!=. ,a(id) cl(id)
est sto m4  //第4列

esttab m3 m4 using 附表8排除内生性2：基于宏观变量的PSM-DID检验.rtf ,keep(did) replace b(%6.4f) se(%6.4f) ar2(3) star(* 0.1 ** 0.05 *** 0.01) compress nogap

*==============附表9 基准回归（逐步回归法）：租赁住房扩张与微观就业规模========*
use data2,clear
xtset id year

areg pop did $con i.year i.industry ,a(id) cl(id)
est sto m1  //第1列
areg pop did $con second i.year i.industry ,a(id) cl(id)
est sto m2  //第2列
areg pop did $con second gfdi i.year i.industry ,a(id) cl(id)
est sto m3  //第3列
areg pop did $con second gfdi lprice i.year i.industry ,a(id) cl(id)
est sto m4  //第4列
areg pop did $con second gfdi lprice lwage_ave i.year i.industry ,a(id) cl(id)
est sto m5  //第5列

esttab m1 m2 m3 m4 m5 using 附表9基准回归（逐步回归法）.rtf ,keep(did $con second gfdi lprice lwage_ave) replace b(%6.4f) se(%6.4f) ar2(3) star(* 0.1 ** 0.05 *** 0.01) compress nogap

*===============================END============================================*
