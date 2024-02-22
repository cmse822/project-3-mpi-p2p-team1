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

 

## Part 3: MPI Ring Shift

  
## Part 4: Non-blocking MPI Ring Shift
