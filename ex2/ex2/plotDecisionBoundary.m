function plotDecisionBoundary(theta, X, y)
%PLOTDECISIONBOUNDARY Plots the data points X and y into a new figure with
%the decision boundary defined by theta
%   PLOTDECISIONBOUNDARY(theta, X,y) plots the data points with + for the 
%   positive examples and o for the negative examples. X is assumed to be 
%   a either 
%   1) Mx3 matrix, where the first column is an all-ones column for the 
%      intercept.
%   2) MxN, N>3 matrix, where the first column is all-ones

% Plot Data
global degree
plotData(X(:,2:3), y);
hold on

if size(X, 2) <= 3
    % Only need 2 points to define a line, so choose two endpoints
    plot_x = [min(X(:,2))-2,  max(X(:,2))+2];

    % Calculate the decision boundary line
    plot_y = (-1./theta(3)).*(theta(2).*plot_x + theta(1));

    % Plot, and adjust axes for better viewing
    plot(plot_x, plot_y)
    
    % Legend, specific for the exercise
    legend('Admitted', 'Not admitted', 'Decision Boundary')
    axis([30, 100, 30, 100])
else
    % Here is the grid range
    u = linspace(min(X(:,2)), max(X(:,2)));
    v = linspace(min(X(:,3)), max(X(:,3)));
    u=transpose(u);
    v=transpose(v);
    z = zeros(length(u), length(v));
    % Evaluate z = theta*x over the grid
    for i = 1:length(u)
        for j = 1:length(v)
            z(i,j) = mapFeature(u(i), v(j),degree)*theta;

% % % %             z(i,j) =
% [1,u(i),v(j),u(i).*v(j),u(i).^2,v(j).^2,u(i).^2.*v(j),u(i).*v(j).^2,u(i).^3,v(j).^3]*theta;
% % only for % [X,X(:,1).*X(:,2),X.^2,X(:,1).^2.*X(:,2),X(:,1).*X(:,2).^2,X.^3]
        end
    end
    z = z'; % important to transpose z before calling contour

    % Plot z = 0
    % Notice you need to specify the range [0, 0]
    
    contour(u, v, z, [0, 0], 'LineWidth', 2)
%     mesh(u,v,z);
%     axis([min(X(:,2)), max(X(:,2)),min(X(:,3)), max(X(:,3)),-2,1])
end
hold off

end
