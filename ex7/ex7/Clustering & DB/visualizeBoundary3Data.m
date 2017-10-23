function visualizeBoundary3Data(X, y, models, varargin)
%VISUALIZEBOUNDARY plots a non-linear decision boundary learned by the SVM
%   VISUALIZEBOUNDARYLINEAR(X, y, model) plots a non-linear decision 
%   boundary learned by the SVM and overlays the data on it

% Plot the training data on top of the boundary
plotData3Data(X, y)

% Make classification predictions over a grid of values
x1plot = linspace(min(X(:,1)), max(X(:,1)), 100)';
x2plot = linspace(min(X(:,2)), max(X(:,2)), 100)';
[X1, X2] = meshgrid(x1plot, x2plot);
vals = zeros(size(X1));
for i = 1:size(X1, 2)
   this_X = [X1(:, i), X2(:, i)];
   vals1(:, i) = svmPredict3Data(models(1),this_X);
   vals2(:, i) = svmPredict3Data(models(2),this_X);
   vals3(:, i) = svmPredict3Data(models(3),this_X);

end

% Plot the SVM boundary
figure(1)
hold on;
contour(X1, X2, vals1, [0 0], 'Color', 'b');
contour(X1, X2, vals2, [0 0], 'Color', 'r');
contour(X1, X2, vals3, [0 0], 'Color', 'g');
hold off;

figure(2)
surface(X1, X2, vals1);
hold on;
surface(X1, X2, vals2);
surface(X1, X2, vals3);
hold off;


end
