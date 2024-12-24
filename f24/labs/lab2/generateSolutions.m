%% test data
test_weights = cell(1,3);
test_heights = cell(1,3);

test_weights{1} = 160;
test_weights{2} = [218.6201 195.6846 167.9708; 187.3783 159.1273 170.9130];
test_weights{3} = normrnd(175, 15, 7, 12);

test_heights{1} = 5.8;
test_heights{2} = [6.3492 6.1508 5.6231; 5.6611 4.7741 5.3882];
test_heights{3} = normrnd(5.8, 0.5, 7, 12);
%% Generate solutions


correct_bmis = cell(1,3);
correct_average_weight = cell(1,3);
correct_average_height = cell(1,3);
correct_average_bmi = cell(1,3);
correct_min_max_bmi = cell(1,3);
for i = 1:3
    correct_bmis{i} = calculateBmis(test_weights{i}, test_heights{i});
    [
        ~,...
        correct_average_weight{i},...
        correct_average_height{i},...
        correct_average_bmi{i},...
        correct_min_max_bmi{i},...
    ] = calculateBmiStats(test_weights{i}, test_heights{i});
end

save("lab_2_solution_data.mat", "test_weights", ...
                                  "test_heights", ...
                                  "correct_bmis", ...
                                  "correct_average_weight", ...
                                  "correct_average_height", ...
                                  "correct_average_bmi", ...
                                  "correct_min_max_bmi");