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

  
## Part 4: Non-blocking MPI Ring Shift
