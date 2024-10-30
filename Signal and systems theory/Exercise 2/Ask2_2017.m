clc;
clear;

m = 7;
k = 1;

syms t w;

%----------------Time-field---------------%
u(t) = heaviside(t);

%------1-------%
p(t) = u(t+k-m) - u(t-k-m);
x1(t) = p(t) + p(t)*cos(pi*t);
%Το σήμα x1(t) με βάσει την p(t) είναι από 6 μέχρι 8, για κάποιο λόγο η
%heaviside δεν το κάνει plot από το 6.25 μεχρι το 8


%------2-------%
x(t) = u(t+k) - u(t-k);
xm(t) = x(t)*cos(k*t)*sin(m*pi*t + pi/3);

%------3-------%
g(t) = t*exp(-m*t)*u(t)*cos(k*t);


%----------------Frequency-field---------------%

%------1-------%
X(w) = (2*sin(k*w)/w)*exp(-1i*m*w) + ((sin(k*(w-pi)))/(w-pi))*exp(-1i*m*(w-pi)) + ((sin(k*(w+pi)))/(w+pi))*exp(-1i*m*(w+pi));
X(w) = abs(X(w));
%------2-------%
Xm(w) = exp(1i*pi/3)*(2*sin(k*(w-pi*(k+m)))/(w-pi*(k+m)) + 2*sin(k*(w-pi*(m-k)))/(w-pi*(m-k)))/(4*1i) - exp(-1i*pi/3)*(2*sin(k*(w-pi*(k-m)))/(w-pi*(k-m)) + 2*sin(k*(w+pi*(m+k)))/(w+pi*(m+k)))/(4*1i);
Xm(w) = abs(Xm(w));

%------3-------%
G(w) = (1/2*(1i*(w-k)+m)^2) + (1/2*(1i*(w+k)+m)^2);
G(w) = abs(G(w));


figure(1);
%----------------Time-plots---------------%
subplot(3,2,1);ezplot(x1(t));
title('Σήμα 1');
subplot(3,2,3);ezplot(xm(t));
title('Σήμα 2');
subplot(3,2,5);ezplot(g(t));
title('Σήμα 3');
%----------------Magnitude-plots---------------%
subplot(3,2,2);ezplot(X(w));
title('Πλάτος 1');
subplot(3,2,4);ezplot(Xm(w));
title('Πλάτος 2');
subplot(3,2,6);ezplot(G(w));
title('Πλάτος 3');

