clear all;
clc;

filename = '/Users/shelton/Downloads/nbpp.csv';
filename2 = '/Users/shelton/Downloads/nbpp-1.csv';
data = readtable(filename);
data2 = readtable(filename2);

Message_Size = data{1:end, 1};
Time_offnode = data{1:end, 2};
Bandwidth_offnode = data{1:end, 3};
Latency_offnode = data{1:end, 4};

Time_onnode = data2{1:end, 2};
Bandwidth_onnode = data2{1:end, 3};
Latency_onnode = data2{1:end, 4};


% Bandwidth plot
figure;
semilogx(Message_Size, Bandwidth_offnode, "LineWidth", 2, "Marker", "o");
hold on;
semilogx(Message_Size, Bandwidth_onnode, "LineWidth", 2, "Marker", "o");
hold off;
xlabel('Message Size (bytes)');
ylabel('Bandwidth (Megabytes/s)');
title('Non-Block Ping-Pong, Bandwidth');
legend("Off Node","On Node")
grid on;
set(gca, 'XMinorGrid', 'on', 'YMinorGrid', 'on');

% Latency plot
figure;
semilogx(Message_Size, Latency_offnode, "LineWidth", 2, "Marker", "o");
hold on;
semilogx(Message_Size, Latency_onnode, "LineWidth", 2, "Marker", "o");
hold off;
xlabel('Message Size (bytes)');
ylabel('Latency (us)');
title('Non-Block Ping-Pong, Latency');
legend("Off Node","On Node")
grid on;
set(gca, 'XMinorGrid', 'on', 'YMinorGrid', 'on');
