function water = reservoir_visualization(water_height)
    % Load variables from .mat file
    load project1_data.mat valley x y;
    % Create meshgrid
    [X, Y] = meshgrid(x,y);

    % Initialize water array to constant height
    water = water_height * ones(size(X));
    % Remove water below valley
    water(water < valley) = NaN;
    % Remove water outside the reservoir
    water(Y < 2200 - 0.8 * X) = NaN;
    

    % Open figure
    figure;
    colormap summer;
    surf(X,Y,valley,EdgeColor="none");
    hold on;
    surf(X,Y,water,EdgeColor="none",FaceColor="Blue");
    xlabel("x (m)");
    ylabel("y (m)");
    zlabel("height (m)");
    hold off;

    saveas(gcf,"reservoir_visualization.jpg");
end