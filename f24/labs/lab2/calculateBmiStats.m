function [bmi, avg_weight, avg_height, avg_bmi, min_max_bmi] = calculateBmiStats(W, H)
    % Convert weight matrix from pounds to kilograms
    W = W ./ 2.205;
    % Convert height matrix from feet to meters
    H = H ./ 3.281;
    % Calculate BMIs
    bmi = W ./ H.^2;
    % Calculate average weight by hospital
    avg_weight = mean(W,2);
    % Calculate average height by hospital
    avg_height = sum(H,2) ./ size(H,2);
    % Calculate average BMI by hospital
    avg_bmi = mean(bmi,2);
    % Calculate minimum and maximum BMI by hospital
    min_bmi = min(bmi, [], 2);
    max_bmi = max(bmi, [], 2);
    min_max_bmi = [min_bmi max_bmi];
end