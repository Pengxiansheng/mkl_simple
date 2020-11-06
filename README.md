README
===========================
##测试结果  
---------------------------
NXN维随机矩阵求逆  
|结果|*100X100*|*500X500*|*2000X2000*|
|-----|-----|-----|-----|
|*llt().solveInPlace()*|9ms|812ms|48863ms|
|*inverse()*|13ms|1100ms|65371ms|
|*MKL llt().solveInPlace()*|*4ms*|*8ms*|*414ms*|
|*MKL inverse()*|71ms|91ms|870ms|  
===========================		
## 注
* #define EIGEN_USE_MKL_ALL 需要写在Eigen头文件前
* llt().solveInPlace() 求逆结果有可能会与原矩阵相乘不为单位正，可以通过在对角元素上加小数解决
* 线程看空闲情况自动分配，可能全部都占（估计学习MKL可以控制）  
* 另外也可以考虑用float型，时间会进一步减少
