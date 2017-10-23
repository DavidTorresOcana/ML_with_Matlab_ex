function [theta, J_history,num_itersDone,fail] = gradientDescentMulti(X, y, theta, alpha, num_iters)
%GRADIENTDESCENTMULTI Performs gradient descent to learn theta
%   theta = GRADIENTDESCENTMULTI(x, y, theta, alpha, num_iters) updates theta by
%   taking num_iters gradient steps with learning rate alpha

% Initialize some useful values
m = length(y); % number of training examples
J_history = zeros(num_iters, 1);
P=plot(J_history);
iter=2;
fail=0;
J_history(1)=computeCostMulti(X, y, theta);
% J_history(iter-1)-J_history(iter)
while iter < num_iters && fail==0;

    % ====================== YOUR CODE HERE ======================
    % Instructions: Perform a single gradient step on the parameter vector
    %               theta. 
    %
    % Hint: While debugging, it can be useful to print out the values
    %       of the cost function (computeCostMulti) and gradient here.
    %



    for j=1:size(X, 2)
        thetaupdt(j)=theta(j)-alpha*(1/m)*sum( (X*theta-y(:,1)).*X(:,j) );
    end
    theta=thetaupdt';
 


    % ============================================================

    % Save the cost J in every iteration    
    J_history(iter) = computeCostMulti(X, y, theta);
    set(P,'XData',1:iter,'YData',J_history(1:iter));
    drawnow;
    

    % Convergencia de la solucion
    if J_history(iter-1)-J_history(iter)<10e-4 && iter>10 
        fail=1; % No existe convergencia de la solucion
    end
    iter=iter+1;

    
end
num_itersDone=iter;


end
