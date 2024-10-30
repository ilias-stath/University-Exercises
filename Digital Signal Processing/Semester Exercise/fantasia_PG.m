%Σταθάκος Ηλίας 2017
%Παπαθανασίου Κωνσταντίνος 2008

function[] = fantasia_PG

t = 'Y';
i = 1;
while i ~= 7
    if i==6 && t == 'Y'
        t = 'O';
        i = 1;
    elseif i==6 && t == 'O'
        break;
    else
        name = append(t,native2unicode(i+48,'ASCII'));
        file = append(name,'.txt');
        RR_intervals = readmatrix(file);
        PG(RR_intervals,name);
        i = i + 1;
    end
end



function[] = PG(RR_intervals,name)

len = length(RR_intervals);
th = pi/4;
lowest_beat = 5;
MO = 0;


% Calculate MO
for i = 1:len
    MO = MO + RR_intervals(i);
    if lowest_beat > RR_intervals(i)
        lowest_beat = RR_intervals(i);
    end

end
MO = MO/len;


% Calculate the standard deviation
RR_std = std(RR_intervals);

% y=-x line
endpoint = 2*MO - lowest_beat;
x = lowest_beat:0.01:endpoint;
y = -x + 2*MO;

% Plot y=x, y=-x, MO
figure;
scatter(RR_intervals(1:end-1),RR_intervals(2:end),'o','MarkerEdgeColor','b');
hold on;
plot(RR_intervals, RR_intervals, 'LineWidth',2,'Color','r');
hold on;
plot(x, y, 'LineWidth', 2,'Color','y');
xlabel('RR_n(s)');
ylabel('RR_n_+_1(s)');
title(name);
grid on;
hold on;
plot(MO,MO,'+','Color','k');
hold on;


% Ellipse settings
a = RR_std*2; %SD2 axis
b = RR_std; %SD1 axis
theta = linspace(0, 2 * pi, 100);
xEllipse = a * cos(theta);
yEllipse = b * sin(theta);

% Rotate ellipse by th
R = [cos(th) -sin(th); sin(th) cos(th)];
rotatedEllipse = R * [xEllipse; yEllipse];

% Plot
plot(rotatedEllipse(1, :) + MO, rotatedEllipse(2, :) + MO, 'k', 'LineWidth', 2);

legend('RR','SD2','SD1','MO','eclipse','Location','southeast');

%3D plot
for i= 1:len-2
    L1(i) = abs(RR_intervals(i) - RR_intervals(i+2));
end


for i= 1:len-1
     D(i) = abs(RR_intervals(i) - RR_intervals(i+1))/sqrt(2);
end

for i= 1:len-3
     L(i) = sqrt(L1(i)^2 + L1(i+1)^2);
     Z(i) = L(i)*(D(i) + 0.01);
end

Z(len-2) = Z(len-3);
Z(len-1) = Z(len-4);

figure;
%scatter3(RR_intervals(1:end-1),RR_intervals(2:end), Z,'o','MarkerEdgeColor','b')
scatter3(RR_intervals(1:end-2),RR_intervals(2:end-1),RR_intervals(3:end),'o','MarkerEdgeColor','b');
xlabel('RR_n(s)');
ylabel('RR_n_+_1(s)');
zlabel('RR_n_+_2(s)');
%zlabel('Z');
title(name);
%scatter([1 2 3 4 5],[1 2 3 4 5],[1 2 3 4 5],'x','MarkerEdgeColor','b');
