clc;
clear;

y=0;

t = -pi:0.01:pi;
x = pi^2 - t.^2;

for n=1:1:10
    y = y + (((-1)^n)*(-4*cos(n*t)))/(n^2);
    if(n==1 | n==2 | n==3 | n==5 | n==10)
        figure(n);
        z = (2*pi^2)/3 + y;
        plot(t,x,'m',t,z,'r');grid on;
        hold on;
    end
end

