# mkl_simple  

mkl加速Eigen矩阵运算的基本包例子

## 测试结果   

NXN维随机矩阵求逆  
|结果|*100X100*|*500X500*|*2000X2000*|
|-----|-----|-----|-----|
|*llt().solveInPlace()*|9ms|812ms|48863ms|
|*inverse()*|13ms|1100ms|65371ms|
|*MKL llt().solveInPlace()*|*4ms*|*8ms*|*414ms*|
|*MKL inverse()*|71ms|91ms|870ms|  


## 注

* #define EIGEN_USE_MKL_ALL 需要写在Eigen头文件前
* llt().solveInPlace() 求逆结果有可能会与原矩阵相乘不为单位正，可以通过在对角元素上加小数解决
* 线程看空闲情况自动分配，可能全部都占（估计学习MKL可以控制）  
* 另外也可以考虑用float型，时间会进一步减少

## 依赖  

* [MKL](https://blog.csdn.net/shenzhongyu24/article/details/109187502?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522160456954219724836751085%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=160456954219724836751085&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_v2~rank_v28-23-109187502.pc_search_result_cache&utm_term=linux+mkl&spm=1018.2118.3001.4449 "悬停显示")
* [BLAS & LAPACK](https://blog.csdn.net/weixin_42621387/article/details/108873382?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522160458412719724835835445%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=160458412719724835835445&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_v2~rank_v28-2-108873382.pc_search_result_cache&utm_term=ubuntu+blas&spm=1018.2118.3001.4449 "悬停显示")

## 本地修改  

* .bashrc 增加 

``` 
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/intel路径/intel/lib/intel64:/intel路径/intel/mkl/lib/intel64
export PATH="$PATH:/intel路径/intel/bin"
source /intel路径/intel/compilers_and_libraries/linux/mkl/bin/mklvars.sh intel64
```
	
## 相关参考  

* [Eigen对不同的稠密矩阵求解器的速度比较](https://eigen.tuxfamily.org/dox/group__DenseDecompositionBenchmark.html "悬停显示")
* [Eigen对MKL加速的说明页](http://eigen.tuxfamily.org/dox/TopicUsingIntelMKL.html "悬停显示")
* [对比不同矩阵运算加速方法](https://github.com/BeanLiu1994/solver_speed_test "悬停显示")
* [依赖于MKL的基本包](https://github.com/openmeeg/findmkl_cmake "悬停显示")
