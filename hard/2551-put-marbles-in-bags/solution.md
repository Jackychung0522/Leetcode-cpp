分 k 組，頭尾一定會選到
因此中間一定是選(k-1）組兩兩相鄰
選擇最大的(k-1)組 與最小的(k-1）組相減就是答案
用加入 vector sort 一次 再從頭和尾巴選比現在(pq)快

ex. [1,3,5,7,2] k=2
1,2 必選 ， k=2 中間選一組
最大(5+7)
最小(1+3）
因此最大為[1,3,5][7,2] (1+5)+(7+2)
最小為[1][3,5,7,2] (1+1)+(3+2)
相減為 8。
cd
