import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

# Read data from the CSV file
filename = '/Users/shelton/Desktop/nbpp.csv'
data = pd.read_csv(filename)

# Extract columns
Message_Size = data.iloc[:, 0]
Bandwidth = data.iloc[:, 2]
Latency = data.iloc[:, 3]

# Set the style of plots
plt.style.use('seaborn-darkgrid')
# Create a color palette
palette = plt.get_cmap('Set1')

# Bandwidth plot
plt.figure(figsize=(10,6))
plt.semilogx(Message_Size, Bandwidth, color=palette(1), linewidth=2, marker='o', label='Bandwidth')
plt.xlabel('Message Size (bytes)', fontsize=14, fontweight='bold')
plt.ylabel('Bandwidth (Megabytes/s)', fontsize=14, fontweight='bold')
plt.title('Non-Block Ping-Pong, Bandwidth', fontsize=16, fontweight='bold')
plt.legend()
plt.grid(True, which='both', ls='--')
plt.gca().xaxis.set_major_formatter(ticker.ScalarFormatter())
plt.gca().xaxis.set_minor_formatter(ticker.ScalarFormatter())

# Latency plot
plt.figure(figsize=(10,6))
plt.semilogx(Message_Size, Latency, color=palette(2), linewidth=2, marker='o', label='Latency')
plt.xlabel('Message Size (bytes)', fontsize=14, fontweight='bold')
plt.ylabel('Latency (us)', fontsize=14, fontweight='bold')
plt.title('Non-Block Ping-Pong, Latency', fontsize=16, fontweight='bold')
plt.legend()
plt.grid(True, which='both', ls='--')
plt.gca().xaxis.set_major_formatter(ticker.ScalarFormatter())
plt.gca().xaxis.set_minor_formatter(ticker.ScalarFormatter())

# Display the plots
plt.show()
