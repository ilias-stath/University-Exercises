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