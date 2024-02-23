# <p style="text-align: center;"> CMSE 822 &nbsp;&nbsp;&nbsp; SS24
## <p style="text-align: center;">  Project 3 MPI Ping-Pong and Ring Shift
<p style="text-align: right; font-size: 18px;">  &#9786; Team 1  </p>
<p style="text-align: right; font-size: 18px;">  Benjamin DalFavero, Reza Khan Mohammadi, Tairan Song, Xiaotian Hua, Ziyu Cheng</p>  


## Part 1 :  Blocking Ping-Pong

On two nodes of amd20, one processor is selected from each node to exchange data, and the results after 100 iterations are as follows:
| Message Size (bytes) | Time (us) | Bandwidth (Megabytes/s) | Latency (us) |
|----------------------|-----------|-------------------------|--------------|
| 2                    | 32.552    | 0.123                   | 16.276       |
| 4                    | 31.246    | 0.256                   | 15.623       |
| 8                    | 30.550    | 0.524                   | 15.275       |
| 16                   | 31.341    | 1.021                   | 15.670       |
| 32                   | 31.778    | 2.014                   | 15.889       |
| 64                   | 32.391    | 3.952                   | 16.195       |
| 128                  | 32.612    | 7.850                   | 16.306       |
| 256                  | 33.672    | 15.206                  | 16.836       |
| 512                  | 33.597    | 30.479                  | 16.799       |
| 1024                 | 35.299    | 58.018                  | 17.650       |
| 2048                 | 37.524    | 109.158                 | 18.762       |
| 4096                 | 48.565    | 168.680                 | 24.283       |

The graphs of message size versus bandwidth and latency are shown as follows:
<img src="./part1_1.png" alt="error" width="800"/>
<img src="./part1_2.png" alt="error" width="800"/>

We can observe that the bandwidth increases with the message size. However, at 170 Megabytes/s, it is far from reaching the maximum bandwidth, so the plot still shows a rapid upward trend.

When the number of processing elements is fixed (2 in this case), the main consideration is the impact of the data size on latency. In the above figure, the latency increases rapidly when the message size exceeds 1024 bytes. This may be due to reaching the maximum transmission unit limit for packets between the two nodes, resulting in latency caused by data segmentation.


## Part 2 :  Non-block Ping-Pong

Due to the significant fluctuations in the data with 100 iterations, increasing the iterations to 500 results in a smoother curve and clearer characteristics. The specific results are as follows:

 | Message Size (bytes) | Time (us) | Bandwidth (Megabytes/s) | Latency (us) |
|----------------------|-----------|-------------------------|--------------|
| 2                    | 12.346    | 0.324                   | 6.173        |
| 4                    | 11.749    | 0.681                   | 5.874        |
| 8                    | 12.355    | 1.295                   | 6.178        |
| 16                   | 12.395    | 2.582                   | 6.198        |
| 32                   | 11.161    | 5.734                   | 5.580        |
| 64                   | 12.658    | 10.112                  | 6.329        |
| 128                  | 12.529    | 20.433                  | 6.264        |
| 256                  | 11.389    | 44.955                  | 5.695        |
| 512                  | 12.692    | 80.682                  | 6.346        |
| 1024                 | 12.726    | 160.926                 | 6.363        |
| 2048                 | 14.883    | 275.205                 | 7.442        |
| 4096                 | 18.485    | 443.172                 | 9.242        |

The graphs of message size versus bandwidth and latency are shown as follows:
<img src="./part2_1.png" alt="error" width="800"/>
<img src="./part2_2.png" alt="error" width="800"/>

Compared to the results in Part 1, the bandwidth under the non-blocking ping-pong scenario exhibits a similar upward trend but with a greater magnitude of increase. Due to non-blocking communication not consuming time on blocking issues, the same message size should result in a larger bandwidth.

The latency also exhibits similar changes. The overall latency is significantly reduced, approximately only 1/3 of the results from Part 1. However, the latency still increases rapidly once the message size exceeds 1024 bytes, likely due to the same reason as analyzed earlier, which is the MTU limit.

## Part 3: MPI Ring Shift

  
## Part 4: Non-blocking MPI Ring Shift
