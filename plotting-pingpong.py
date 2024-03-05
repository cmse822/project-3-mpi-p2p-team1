import pandas as pd
import matplotlib.pyplot as plt

# Read data from the CSV file
filename = '/Users/shelton/Desktop/nbpp.csv'
data = pd.read_csv(filename)

# Extract columns
Message_Size = data.iloc[:, 0]
Bandwidth = data.iloc[:, 2]
Latency = data.iloc[:, 3]

# Bandwidth plot
plt.figure()
plt.semilogx(Message_Size, Bandwidth, linewidth=2, marker='o')
plt.xlabel('Message Size (bytes)')
plt.ylabel('Bandwidth (Megabytes/s)')
plt.title('Non-Block Ping-Pong, Bandwidth')
plt.grid(which='both', axis='both')

# Latency plot
plt.figure()
plt.semilogx(Message_Size, Latency, linewidth=2, marker='o')
plt.xlabel('Message Size (bytes)')
plt.ylabel('Latency (us)')
plt.title('Non-Block Ping-Pong, Latency')
plt.grid(which='both', axis='both')

plt.show()
