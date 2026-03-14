********************************************************************************
*================《"安居"方能"乐业"：租赁住房供给与稳就业》====================*
*******************************************************************************
*=========================使用软件Stata/MP 17.0================================*


*======表1 租赁住房供给政策的宏观处理效应======================================*
use data1,clear
xtset city year
areg zlhouse did  gexp gdeposit second lrgdp gfdi lprice lwage_ave  i.year,a(city) cl(city)
est store m1  //第1列
areg rentprice did gexp gdeposit second lrgdp gfdi lwage_ave i.year  ,a(city) cl(city)
est store m3  //第3列
areg rent_wage did gexp gdeposit second lrgdp gfdi lprice i.year ,a(city) cl(city)
est store m4  //第4列
areg res_pop did  gexp gdeposit second lrgdp gfdi lprice lwage_ave  i.year,a(city) cl(city)
est store m5  //第5列
areg lemployee did  gexp gdeposit second lrgdp gfdi lprice lwage_ave  i.year,a(city) cl(city)
est store m6  //第6列
esttab m1 m3 m4 m5 m6 using 表1租赁住房供给政策的宏观处理效应.rtf ,keep(did) replace b(%6.4f) se(%6.4f) ar2(3) star(* 0.1 ** 0.05 *** 0.01) compress nogap

use data5,clear //替换为月度租金数据
reghdfe lsupply did gexp gdeposit second lrgdp gfdi lprice lwage_ave,a(city year#month) cl(city)
est store m2  //第2列：由于签署保密协议，被解释变量lsupply的数据为保密数据
esttab m2 using 表1租赁住房供给政策的宏观处理效应.rtf ,keep(did) replace b(%6.4f) se(%6.4f) ar2(3) star(* 0.1 ** 0.05 *** 0.01) compress nogap

*=======附表2 主要变量定义与描述性统计——城市层面变量===========================*
use data1,clear
sum rentprice rent_wage zlhouse res_pop lemployee lrgdp gexp gdeposit second gfdi lprice lwage_ave
sum2docx rentprice rent_wage zlhouse res_pop lemployee lrgdp gexp gdeposit second gfdi lprice lwage_ave using 附表2城市层面主要变量定义与描述性统计.docx,replace stats (N mean(%9.4f) sd(%9.4f) min(%9.4f) max(%9.4f)) title("附表2主要变量定义与描述性统计")

use data5,clear //替换为月度租金数据
sum lsupply     //月度租金数据的描述性统计，lsupply的数据为保密数据
sum2docx lsupply using 附表2城市层面主要变量定义与描述性统计.docx,replace stats (N mean(%9.4f) sd(%9.4f) min(%9.4f) max(%9.4f)) title("附表2主要变量定义与描述性统计")

*=======附表3 租赁住房供给政策的落地成效检验===================================*
use data1,clear
xtset city year
areg zlhouse did  gexp gdeposit second lrgdp gfdi lprice lwage_ave  i.year,a(city) cl(city)
est store m1  //第1列
areg zlhouse did  gexp gdeposit second lrgdp gfdi lprice lwage_ave  i.year i.year#i.prov,a(city) cl(city)
est store m2  //第2列
esttab m1 m2 using 附表3租赁住房供给政策的落地成效检验.rtf ,keep(did) replace b(%6.4f) se(%6.4f) ar2(3) star(* 0.1 ** 0.05 *** 0.01) compress nogap

use data5,clear //替换为月度租金数据
reghdfe lsupply did gexp gdeposit second lrgdp gfdi lprice lwage_ave,a(city year#month) cl(city) 
est sto m3 //第3列：由于签署保密协议，被解释变量lsupply的数据为保密数据
reghdfe lsupply did gexp gdeposit second lrgdp gfdi lprice lwage_ave,a(city year#month year#prov) cl(city)
est sto m4 //第4列：由于签署保密协议，被解释变量lsupply的数据为保密数据
esttab m3 m4 using 附表3租赁住房供给政策的落地成效检验.rtf ,keep(did) replace b(%6.4f) se(%6.4f) ar2(3) star(* 0.1 ** 0.05 *** 0.01) compress nogap

*========附表4 租赁住房供给政策的宏观处理效应==================================*
use data1,clear
xtset city year

areg rentprice did gexp gdeposit second lrgdp gfdi lwage_ave i.year  ,a(city) cl(city)
est store m1  //第1列
areg rentprice did gexp gdeposit second lrgdp gfdi lwage_ave i.year i.year#i.prov ,a(city) cl(city)
est store m2  //第2列
areg rent_wage did gexp gdeposit second lrgdp gfdi lprice i.year ,a(city) cl(city)
est store m3  //第3列
areg rent_wage did gexp gdeposit second lrgdp gfdi lprice i.year i.year#i.prov ,a(city) cl(city)
est store m4  //第4列
areg res_pop did  gexp gdeposit second lrgdp gfdi lprice lwage_ave  i.year,a(city) cl(city)
est store m5  //第5列
areg res_pop did  gexp gdeposit second lrgdp gfdi lprice lwage_ave  i.year i.year#i.prov,a(city) cl(city)
est store m6  //第6列
areg lemployee did  gexp gdeposit second lrgdp gfdi lprice lwage_ave  i.year,a(city) cl(city)
est store m7  //第7列
areg lemployee did  gexp gdeposit second lrgdp gfdi lprice lwage_ave  i.year i.year#i.prov ,a(city) cl(city)
est store m8  //第8列

esttab m1 m2 m3 m4 m5 m6 m7 m8 using 附表4租赁住房供给政策的宏观处理效应.rtf ,keep(did) replace b(%6.4f) se(%6.4f) ar2(3) star(* 0.1 ** 0.05 *** 0.01) compress nogap

*=========END==================================================================*