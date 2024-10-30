%Κουτσούκης Απόστολος 1978
%Παπαθανασίου Κωνσταντίνος 2008
%Σταθάκος Ηλίας 2017

function erg1_11
    clc;
    clear;

    tp_m = zeros(1, 35);
    tc_m = zeros(1, 35);
    tg_m = zeros(1, 35);
    tm_m = zeros(1, 35);

    for n=4:35
        e = [0 0 round(10*rand(1,n-2))+1];
        c = [0 round(10*rand(1,n-1))+1];
        d = [round(10*rand(1,n))+1];
        a = [round(10*rand(1,n-1))+1 0];
        b = [round(10*rand(1,n-2))+1 0 0];
    
        p = pendatiagonal(e,c,d,a,b,n);
        y = round(100*rand(n,1))+1;

        for i=1:10
            tic; [x,t] = PTRANSII(n,e,c,d,a,b,y); tp(i)=toc;
            tic; cramer(p,y); tc(i)=toc;
            tic; gaussianElimination(p,y); tg(i)=toc;
            tic; matlab = (p\y)'; tm(i)=toc;
            tp_m(n) = tp_m(n) + tp(i);
            tc_m(n) = tc_m(n) + tc(i);
            tg_m(n) = tg_m(n) + tg(i);
            tm_m(n) = tm_m(n) + tm(i);
        end
        tp_m(n) = tp_m(n)/10;
        tc_m(n) = tc_m(n)/10;
        tg_m(n) = tg_m(n)/10;
        tm_m(n) = tm_m(n)/10;
        
    end
    
    n=1:35;
    figure(1);
    plot(n,tp_m,'m',n,tc_m,'y',n,tg_m,'g',n,tm_m,'r'); grid on;
    legend('PTRANSII','cramer','gaussian','matlab')
    hold on;
    

    tp_m = zeros(1, 40);
    tm_m = zeros(1, 40);
    
    for n=4:50:2000
        e = [0 0 round(10*rand(1,n-2))+1];
        c = [0 round(10*rand(1,n-1))+1];
        d = [round(10*rand(1,n))+1];
        a = [round(10*rand(1,n-1))+1 0];
        b = [round(10*rand(1,n-2))+1 0 0];
        
        p = pendatiagonal(e,c,d,a,b,n);
        y = round(100*rand(n,1))+1;

        for i=1:10
            tic; [x] = PTRANSII(n,e,c,d,a,b,y); tp(i)=toc;
            tic; matlab = (p\y)'; tm(i)=toc;
            tp_m((n-4)/50 + 1) = tp_m((n-4)/50 + 1) + tp(i);
            tm_m((n-4)/50 + 1) = tm_m((n-4)/50 + 1) + tm(i);
        end
        tp_m((n-4)/50 + 1) = tp_m((n-4)/50 + 1)/10;
        tm_m((n-4)/50 + 1) = tm_m((n-4)/50 + 1)/10;
        
    end
    
    
    n=1:40;
    figure(2);
    plot(n*50,tp_m,'m',n*50,tm_m,'r'); grid on;
    legend('PTRANSII','matlab')
    

end

%---------------------------------------------------

function p = pendatiagonal(e,c,d,a,b,n)
    p = diag(d) + diag(a(1:n-1),1) + diag(b(1:n-2),2) + diag(c(2:n),-1) + diag(e(3:n),-2);


end

%----------------------------------------------------------
function [x,t] = PTRANSII(n,e,c,d,a,b,y)
t(n) = d(n);
k(n) = c(n)/t(n);
r(n) = e(n)/t(n);
z(n) = y(n)/t(n);

l(n-1) = a(n-1);
t(n-1) = d(n-1) - k(n)*l(n-1);
k(n-1) = (c(n-1) - r(n)*l(n-1))/t(n-1);
r(n-1) = e(n-1)/t(n-1);
z(n-1) = (y(n-1)-z(n)*l(n-1))/t(n-1);

for i=n-2:-1:3
    l(i) = a(i) - k(i+2)*b(i);
    t(i) = d(i) - r(i+2)*b(i) - k(i+1)*l(i);
    k(i) = (c(i) - r(i+1)*l(i))/t(i);
    t(i) = e(i)/t(i);
    z(i) = (y(i) - z(i+2)*b(i) - z(i+1)*l(i))/t(i);
end

l(2) = a(2) - k(4)*b(2);
t(2) = d(2) - r(4)*b(2) - k(3)*l(2);
k(2) = (c(2) - r(3)*l(2))/t(2);
l(1) = a(1) - k(3)*b(1);
t(1) = d(1) - r(3)*b(1) - k(2)*l(1);
z(2) = (y(2) - z(4)*b(2) - z(3)*l(2))/t(2);
z(1) = (y(1) - z(3)*b(1) - z(2)*l(1))/t(1);

x(1) = z(1);
x(2) = z(2) - k(2)*x(1);

for i=3:1:n
    x(i) = z(i) - k(i)*x(i-1) - r(i)*x(i-2);
end


end


%----------------------------------------
function x = cramer(A,b)
% Description: Solves Ax = b using the Cramer rule
% Input: 
%   - A: the coefficient matrix
%   - b: the right-hand side values
% Output: 
%   - x: the solution vector
% Author: Markos Tsipouras

	p = det(A); 
	x = zeros(size(b));
	for j = 1:size(b)
		x(j) = det([A(:,1:j-1) b A(:,j+1:end)]) / p;
	end
end

%---------------------------------------------------

function x = gaussianElimination(A, b)
% Description: Solves Ax = b using the Gaussian elimination with partial pivoting
% Input: 
%   - A: the coefficient matrix
%   - b: the right-hand side values
% Output: 
%   - x: the solution vector
% Author:  Markos Tsipouras

	[~, n] = size(A);
	Ag = [A b];
	
	% elimination phase
	for k = 1:n - 1
		% partial pivoting
		[~, j] = max(abs(Ag(k:n, k)));
		C = Ag(k, :);
		Ag(k, :) = Ag(j + k - 1, :);
		Ag(j + k - 1, :) = C;
		if Ag(k, k) == 0
			error('Matrix A is singular');
		end
		for i = k + 1:n
			r = Ag(i, k) / Ag(k, k);
			Ag(i, k:n + 1) = Ag(i, k:n + 1) - r * Ag(k, k: n + 1);
		end
	end
	
	% back substitution phase
	x = zeros(n, 1);
	x(n) = Ag(n, n + 1) / Ag(n, n);
	for k = n - 1:-1:1
		x(k) = (Ag(k, n + 1) - Ag(k, k + 1:n) * x(k + 1:n)) / Ag(k, k);
	end
end