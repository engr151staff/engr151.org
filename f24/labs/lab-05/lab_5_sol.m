%% Read in all data
schools = readmatrix("stats.xlsx",Sheet="football_wins",Range="B1:G1",OutputType="string");
years = readmatrix("stats.xlsx",Sheet="football_wins",Range="A2:A20");
fb_wins = readmatrix("stats.xlsx",Sheet="football_wins",Range="B2:G20");
fb_total = readmatrix("stats.xlsx",Sheet="football_total",Range="B2:G20");
bb_wins =  readmatrix("stats.xlsx",Sheet="basketball_wins",Range="B2:G20");
bb_total = readmatrix("stats.xlsx",Sheet="basketball_total",Range="B2:G20");

%% Calculate win ratios and average win ratios
fb_win_ratios = fb_wins ./ fb_total;
bb_win_ratios = bb_wins ./ bb_total;

avg_fb_win_ratios = mean(fb_win_ratios);
avg_bb_win_ratios = mean(bb_win_ratios);

bar_data = [avg_fb_win_ratios; avg_bb_win_ratios];

%% Write results to sheet
writematrix(schools,"stats1.xlsx",Sheet="ratios",Range="A1:F1");
writematrix(bar_data,...
            "stats1.xlsx",...
            Sheet="ratios",...
            Range="A2:F3");

%% Plot as a bar chart
figure; hold on; grid on;
b = bar(categorical(schools), bar_data);
legend("Football","Basketball",Interpreter="latex");
ylabel("Win Ratio",Interpreter="latex");
xlabel("School",Interpreter="latex");
title("Average Win Ratio from 2000 to 2018",Interpreter="latex");
b(1).FaceColor="#FBFF5C";
b(1).EdgeColor="#0023BE";
b(2).FaceColor="#0023BE";
b(2).EdgeColor="#0023BE";