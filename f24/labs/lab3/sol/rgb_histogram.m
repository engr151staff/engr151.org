%% miyi 09/09/2020
image = imread("color_code_rgb.jpg");
image2 = imread("color_decoded.jpg");

% Find intensities for each color
red_int = image(:,:,1);
green_int = image(:,:,2);
blue_int = image(:,:,3);

% Plot them. Labeling each with their appropriate color.
figure(1)
subplot(1,2,1)
histogram(red_int, 'FaceColor', 'red')
hold on;
histogram(green_int, 'FaceColor', 'green')
histogram(blue_int, 'FaceColor', 'blue')

% Aesthetics
ylabel("Number of Pixels")
xlabel("Bins for Intensity (0 - 255)")
legend("Red Pixels", "Green Pixels", "Blue Pixels")
title("RGB Intensities Histogram Non-Decoded")

% Find intensities for each color
red_int2 = image2(:,:,1);
green_int2 = image2(:,:,2);
blue_int2 = image2(:,:,3);

% Plot them. Labeling each with their appropriate color.
subplot(1,2,2)
histogram(red_int2, 'FaceColor', 'red')
hold on;
histogram(green_int2, 'FaceColor', 'green')
histogram(blue_int2, 'FaceColor', 'blue')

% Aesthetics
ylabel("Number of Pixels")
xlabel("Bins for Intensity (0 - 255)")
legend("Red Pixels", "Green Pixels", "Blue Pixels")
title("RGB Intensities Histogram Decoded")

saveas(figure(1), 'hist_output', 'jpg');

%{
Rubric


AUTOGRADER
Check imread is used
Check for hold on
Check students did NOT use for loops or while loops
Check histogram is used.
Check that "FaceColor" is used
Check ylabel, xlabel, legend, and title keywords
%}