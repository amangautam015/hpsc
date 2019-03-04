# HPSC ASSIGNMENTS 1 (ME 766)
Language used : C++ <br>
Function to Integrate : `f(x) = sin(x)` <br>
Limits: `[0,pi]` <br>
Analytical Value of Integral: **2.00** <br>
Repository : [Source Files](https://github.com/amangautam015/hpsc "Src")

## TRAPEZOIDAL RULE

Code : [trapezoidal.cpp](https://github.com/amangautam015/hpsc/blob/master/trapezoidal.cpp "trapezoidal")  :link:


As number of steps are increased error in final result is reduced dramatically(_almost eponential_) it almost goes to zero at `N = 2000`

A graph showing error Vs log(number of steps) is show below . <br>

**Trapezoidal Rule**

![alt text](https://raw.githubusercontent.com/amangautam015/hpsc/master/ten.png)

<br>

**Average Time Taken vs number of threads**

|Threads  | Average Time(Over 5 trys) |
| ------------- | ------------- |
| 2  | 0.072 sec  |
| 4  | 0.068 sec  |
| 6  | 0.042 sec  |
| 8  | 0.040 sec  |

<br>

Trapezoidal method for given function is pretty fast and it was difficult to observe time reduction with increase in threads however on increasing number of threads to a appretiably large number we could see how increasing threads made programme faster

---

## MONTECARLO METHOD

Code : [montecarlo.cpp](https://github.com/amangautam015/hpsc/blob/master/montecarlo.cpp "trapezoidal")  :link:


As number of steps are increased error in final result is reduced . But in contrast with Trapezoidal rule error is much higher 

A graph showing error Vs log(number of steps) is show below . <br>

**Montecarlo Method**

![alt text](https://raw.githubusercontent.com/amangautam015/hpsc/master/MONTE.png)
 
<br>

**Average Time Taken vs number of threads**

|Threads  | Average Time(Over 5 trys) |
| ------------- | ------------- |
| 2  | 7.06 sec  |
| 4  | 4.95 sec  |
| 6  | 4.97 sec  |
| 8  | 4.97 sec  |

<br>

Time taken is reduced as threads are increased however montecarlo method is not as good as trapezoidal method for **one dimensional** integration.It must be noted that _**montecarlo method does more conditional checks than trapezoidal rule**_ which leads to increase in processing time .Also gets a random double between `[0,1]` .All these factors reducecs speed for montecarlo

> My ALgorithm for **montecarlo** do not preserve **reproducibility** because it takes out a **random number every time it loops** which results in slightly different results .

<br>

---

`g++ filename.cpp -fopenmp -lm` <br>
`time ./a.out`

---

###### Aman Gautam
###### 150100087
