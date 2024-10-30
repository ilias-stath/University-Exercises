clear;
clc;

t = -10:0.01:10;
k = 1/4;
m = 7/4;

x11 = zeros(size(t));
x11(t>-m) = 1;
x1 = k*x11;

x21 = zeros(size(t));
x21(t>-m) = 1;
x22 = zeros(size(t));
x22(t>1) = 1;
x2 = x21 - x22;

x31 = exp(-k*t);
x32 = zeros(size(t));
x32(t>-2) = 1;
x33 = zeros(size(t));
x33(t>k) = 1;
x3 = x31.*(x32 - x33);

x4 = zeros(size(t));
x4((-m*pi<=t)&(t<m*pi)) = k;

x51 = zeros(size(t));
x51(t>-1) = 1;
x52 = zeros(size(t));
x52(t>2) = 1;
x5 = x51 - x52;


h11 = exp(-m*t);
h12 = zeros(size(t));
h12(t>k) = 1;
h1 = h11.*h12;

h2 = exp(-(m*t.^2)/k);

h31 = zeros(size(t));
h31(t>0) = 1;
h3 = k.*h31 - m;

h4 = cos(m.*t);

h5 = zeros(size(t));
h5((-k<=t)&(t<k)) = m;

ts1 = -1.75:0.01:-0.25;
tp1 = -0.25:0.01:10;
r = conv(x1, h1).*0.01;
l = conv(x2, h2).*0.01;
k = conv(x3,h3).*0.01;
g = conv(x4,h4).*0.01;
m = conv(x5,h5).*0.01;

figure(1);
subplot(3,1,1); plot(t,x1); grid on;
xlabel('t'); ylabel('x1');
subplot(3,1,2); plot(t,h1); grid on;
subplot(3,1,2); plot(t,h1); grid on;
xlabel('t'); ylabel('h1');
subplot(3,1,3); plot(r); grid on;
%subplot(3,1,3); plot(tp1,z,ts1,l); grid on;
xlabel('t'); ylabel('x1*h1');
hold on;

figure(2);
subplot(3,1,1); plot(t,x2); grid on;
xlabel('t'); ylabel('x2');
subplot(3,1,2); plot(t,h2); grid on;
xlabel('t'); ylabel('h2');
subplot(3,1,3); plot(l); grid on;
xlabel('t'); ylabel('x2.*h2');
hold on;

figure(3);
subplot(3,1,1); plot(t,x3); grid on;
xlabel('t'); ylabel('x3');
subplot(3,1,2); plot(t,h3); grid on;
xlabel('t'); ylabel('h3');
subplot(3,1,3); plot(k); grid on;
xlabel('t'); ylabel('x3*h3');
hold on;

figure(4);
subplot(3,1,1); plot(t,x4); grid on;
xlabel('t'); ylabel('x4');
subplot(3,1,2); plot(t,h4); grid on;
xlabel('t'); ylabel('h4');
subplot(3,1,3); plot(g); grid on;
xlabel('t'); ylabel('x4*h4');
hold on;

figure(5);
subplot(3,1,1); plot(t,x5); grid on;
xlabel('t'); ylabel('x5');
subplot(3,1,2); plot(t,h5); grid on;
xlabel('t'); ylabel('h5');
subplot(3,1,3); plot(m); grid on;
xlabel('t'); ylabel('x5*h5');
hold on;
