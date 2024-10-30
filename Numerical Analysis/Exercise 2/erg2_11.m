function erg2_11
    % Ergasia 2 - 05_2023

    clc;

    f = @(x) x^2 -4*sin(x);
    df = @(x) 2*x -4*cos(x);

    tol = 10^-7;
    max_it = 50;

    a = 1; b = 6; i = 1;
    fprintf('\n\n\n');
    fprintf('---- Bisect ----\n'); bisect(f,a,b,tol,max_it);
    fprintf('---- Bisect Rec ----\n'); bisect_r(f,a,b,i,tol,max_it);

    x0 = 6; i = 1;
    fprintf('\n\n\n');
    fprintf('--- NewtRaph ---\n'); newton_raphson(f,df,x0,tol,max_it);
    fprintf('--- NewtRaph Rec ---\n'); newton_raphson_r(f,df,x0,i,tol,max_it);

    x0 = 6; x1 = 7; i = 1;
    fprintf('\n\n\n');
    fprintf('---- Secant ----\n'); secant(f,x0,x1,tol,max_it);
    fprintf('---- Secant Rec ----\n'); secant_r(f,x0,x1,i,tol,max_it);
end

function x = bisect(f, a, b, tol, max_it)
% Description: Finds a root of f in the interval [a, b] with precision tol
% using the bisect method
% Input: 
%   - f: the function
%   - a: the lower value of the interval
%   - b: the upper value of the interval
%   = tol: the tolerance
%   - max_it: the maximum number of iterations
% Output: 
%   - x: the root of f
% Author: Markos Tsipouras

    fa = feval(f, a);
    fb = feval(f, b);
    
    i = 1;
    x_previous = b;
	while i <= max_it
        x = (a + b) / 2;
        fprintf('Iteration %3d: %10.8f\n', i, x);
        i = i + 1;
        fx = feval(f, x);
        if fx == 0
            return;
        end
        if fb * fx < 0
            a = x;
            fa = fx;
        else
            b = x;
            fb = fx;
        end
        if abs(x - x_previous) < tol
            return;
        end
        x_previous = x;
    end
end

function x = bisect_r(f, a, b, i, tol, max_it)
% Description: Finds a root of f in the interval [a, b] with precision tol
% using the recurrent bisect method
% Input: 
%   - f: the function
%   - a: the lower value of the interval
%   - b: the upper value of the interval
%   - i: num of iteration 
%   = tol: the tolerance
%   - max_it: the maximum number of iterations
% Output: 
%   - x: the root of f
% Author: you!!!
%x = bisect_r(f,a,x,i,tol, max_it);

    fa = feval(f,a);
    fb = feval(f,b);
    x_previous = b;
    if i >= max_it
        return;
    else
        x = (a + b) / 2;
        fprintf('Iteration %3d: %10.8f\n', i, x);
        i = i + 1;
        fx = feval(f, x);
        if fx == 0
            fprintf('Iteration %3d: %10.8f\n', i, x);
            return;
        end
        if abs(x - x_previous) < tol
            return;
        end
        if fb * fx < 0
           bisect_r(f,x,b,i,tol, max_it);
        else
           bisect_r(f,a,x,i,tol, max_it);
        end
    end
end

function x = newton_raphson(f, df, x0, tol, max_it)
% Description: Finds a root of f starting from x0 with precision tol
% using the Newton-Raphson method
% Input: 
%   - f: the function
%   - df: the derivative of the function
%   - x0: the initial guess
%   = tol: the tolerance
%   - max_it: the maximum number of iterations
% Output: 
%   - x: the root of f
% Author: Markos Tsipouras

    i = 1;

    x = x0;

    x_previous = x0;
	while i <= max_it
        dx = feval(f, x_previous) / feval(df, x_previous);
        x = x_previous - dx;
        fprintf('Iteration %3d: %10.8f\n', i, x);
        i = i + 1;
        if abs(x - x_previous) < tol
            return;
        end
        x_previous = x;
    end
end

function x = newton_raphson_r(f, df, x0, i, tol, max_it)
% Description: Finds a root of f starting from x0 with precision tol
% using the recurrent Newton-Raphson method
% Input:
%   - f: the function
%   - df: the derivative of the function
%   - x0: the initial guess
%   - i: num of iteration 
%   = tol: the tolerance
%   - max_it: the maximum number of iterations
% Output:
%   - x: the root of f
% Author: you!!!

    x = x0;

    x_previous = x0;
    if(i >= max_it)
        return;
    else
        dx = feval(f, x_previous) / feval(df, x_previous);
        x = x_previous - dx;
        fprintf('Iteration %3d: %10.8f\n', i, x);
        i = i + 1;
        if abs(x - x_previous) < tol
            return;
        end
        x = newton_raphson_r(f, df, x, i, tol, max_it);
    end
    
    
end

function x = secant(f, x0, x1, tol, max_it)
% Description: Finds a root of f starting from x0, x1 with precision tol
% using the secant method
% Input: 
%   - f: the function
%   - x0: the initial guess
%   - x1: the initial guess
%   = tol: the tolerance
%   - max_it: the maximum number of iterations
% Output: 
%   - x: the root of f
% Author: Markos Tsipouras

    i = 1;
	while i <= max_it
        f0 = feval(f, x0);
        f1 = feval(f, x1);
        x = x1 - f1 * (x1 - x0) / (f1 - f0);
        fprintf('Iteration %3d: %10.8f\n', i, x);
        i = i + 1;
        if abs(x - x1) < tol
            return;
        end
        x0 = x1;
        x1 = x;
    end
end

function x = secant_r(f, x0, x1, i, tol, max_it)
% Description: Finds a root of f starting from x0, x1 with precision tol
% using the recurrent secant method
% Input: 
%   - f: the function
%   - x0: the initial guess
%   - x1: the initial guess
%   - i: num of iteration 
%   = tol: the tolerance
%   - max_it: the maximum number of iterations
% Output: 
%   - x: the root of f
% Author: you!!!
    
    if(i >= max_it)
        return;
    else
        f0 = feval(f, x0);
        f1 = feval(f, x1);
        x = x1 - f1 * (x1 - x0) / (f1 - f0);
        fprintf('Iteration %3d: %10.8f\n', i, x);
        i = i + 1;
        if abs(x - x1) < tol
            return;
        end
        x0 = x1;
        x1 = x;
        x = secant_r(f, x0, x1, i, tol, max_it);
    end
    
end