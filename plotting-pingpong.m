clear all;
clc;

filename = '/Users/shelton/Desktop/nbpp.csv';
data = readtable(filename);

Message_Size = data{1:end, 1};
Time = data{1:end, 2};
Bandwidth = data{1:end, 3};
Latency = data{1:end, 4};

% Bandwidth plot
figure;
semilogx(Message_Size, Bandwidth, "LineWidth", 2, "Marker", "o");
xlabel('Message Size (bytes)');
ylabel('Bandwidth (Megabytes/s)');
title('Non-Block Ping-Pong, Bandwidth');
grid on;
set(gca, 'XMinorGrid', 'on', 'YMinorGrid', 'on');

% Latency plot
figure;
semilogx(Message_Size, Latency, "LineWidth", 2, "Marker", "o");
xlabel('Message Size (bytes)');
ylabel('Latency (us)');
title('Non-Block Ping-Pong, Latency');
grid on;
set(gca, 'XMinorGrid', 'on', 'YMinorGrid', 'on');