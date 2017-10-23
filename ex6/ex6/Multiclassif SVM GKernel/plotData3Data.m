function plotData3Data(X, y)
%PLOTDATA Plots the data points X and y into a new figure 
%   PLOTDATA(x,y) plots the data points with + for the positive examples

Uno = find(y == 1); Zero = find(y == 0);Dos= find(y == 2);

% Plot Examples
plot(X(Uno, 1), X(Uno, 2), 'k+','LineWidth', 1, 'MarkerSize', 7)
hold on;
plot(X(Zero, 1), X(Zero, 2), 'ko', 'MarkerFaceColor', 'y', 'MarkerSize', 7)
plot(X(Dos, 1), X(Dos, 2), 'kp', 'MarkerFaceColor', 'g', 'MarkerSize', 7)
hold off;

end
