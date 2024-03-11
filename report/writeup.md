# <p style="text-align: center;"> CMSE 822 &nbsp;&nbsp;&nbsp; SS24
## <p style="text-align: center;">  Project 3 MPI Ping-Pong and Ring Shift
<p style="text-align: right; font-size: 18px;">  &#9786; Team 1  </p>
<p style="text-align: right; font-size: 18px;">  Benjamin DalFavero, Reza Khan Mohammadi, Tairan Song, Xiaotian Hua, Ziyu Cheng</p>  


## Part 1 :  Blocking Ping-Pong

The graphs of message size versus bandwidth and latency are shown as follows:
<img src="./part1_1.png" alt="error" width="800"/>
<img src="./part1_2.png" alt="error" width="800"/>

We can observe that the bandwidth increases with the message size. It can be observed that when 2 processors are on the same node, the bandwidth is greater. However, when the message size reaches 4096 bytes, the on-node bandwidth does not continue to increase. After computing more data points between 2048 to 4096 bytes, it was found that after the message size reaches approximately 3500 bytes, the bandwidth almost reaches its peak and no longer monotonically increases.

When 2 processors are on the same node, the latency is lower. If the number of processing elements is fixed, the main consideration is the impact of the data size on latency. As an example of off-node plot, the latency increases rapidly when the message size exceeds 1024 bytes. This may be due to reaching the maximum transmission unit limit for packets between the two nodes, resulting in latency caused by data segmentation.


## Part 2 :  Non-block Ping-Pong

Due to the significant fluctuations in the data with 100 iterations, increasing the iterations to 500 results in a smoother curve and clearer characteristics. The graphs of message size versus bandwidth and latency are shown as follows:
<img src="./part2_1.png" alt="error" width="800"/>
<img src="./part2_2.png" alt="error" width="800"/>

Compared to the results in Part 1, the bandwidth under the non-blocking ping-pong scenario exhibits a similar upward trend but with a greater magnitude of increase. Due to non-blocking communication not consuming time on blocking issues, the same message size should result in a larger bandwidth.

The latency also exhibits similar changes. The overall latency is significantly reduced, approximately only 1/3 ~ 1/2 of the results from Part 1. However, the latency still increases rapidly once the message size exceeds 1024 bytes, likely due to the same reason as analyzed earlier, which is the MTU limit.

## Part 3: MPI Ring Shift

| Message Size (bytes) | Bandwidth (Megabytes/s) | Latency (us) |
|----------------------|-------------------------|--------------|
| 2                    | 13.351135               | 0.149800     |
| 4                    | 27.247956               | 0.146800     |
| 8                    | 54.403264               | 0.147050     |
| 16                   | 130.505710              | 0.122600     |
| 32                   | 365.296804              | 0.087600     |
| 64                   | 673.329826              | 0.095050     |
| 128                  | 1294.236603             | 0.098900     |
| 256                  | 1827.918600             | 0.140050     |
| 512                  | 1094.017094             | 0.468000     |
| 1024                 | 5188.750950             | 0.197350     |
| 2048                 | 8478.575864             | 0.241550     |
| 4096                 | 3705.110810             | 1.105500     |

<img src="part3_1.png" alt="error" width="800"/>
<img src="part3_2.png" alt="error" width="800"/>

  
## Part 4: Non-blocking MPI Ring Shift

| Message Size (bytes) | Bandwidth (Megabytes/s) | Latency (us) |
|----------------------|-------------------------|--------------|
| 2                    | 12.965964               | 0.154250     |
| 4                    | 27.835769               | 0.143700     |
| 8                    | 50.648940               | 0.157950     |
| 16                   | 101.813554              | 0.157150     |
| 32                   | 140.907089              | 0.227100     |
| 64                   | 413.169787              | 0.154900     |
| 128                  | 517.904107              | 0.247150     |
| 256                  | 1415.929204             | 0.180800     |
| 512                  | 1686.985173             | 0.303500     |
| 1024                 | 1719.996641             | 0.595350     |
| 2048                 | 2825.412154             | 0.724850     |
| 4096                 | 2692.611097             | 1.521200     |

<img src="part4_1.png" alt="error" width="800"/>
<img src="part4_2.png" alt="error" width="800"/>
