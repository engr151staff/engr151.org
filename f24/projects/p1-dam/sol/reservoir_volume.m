function volume = reservoir_volume(water_height)
    load project1_data.mat valley x y;

    dx = x(2) - x(1);
    dy = y(2) - y(1);

    [X,Y] = meshgrid(x,y);

    water_depth = water_height * ones(size(X));
    water_depth = water_depth - valley;
    water_depth(water_depth < 0) = 0;
    water_depth(Y < 2200 - 0.8 * x) = 0;

    volume = sum(water_depth,"all") * dx * dy * 1e-6;
end