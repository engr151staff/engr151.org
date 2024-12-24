function power_gw = max_power(water_height, eta, mass_rate)
    load project1_data.mat valley;

    head = water_height - min(valley,[],"all");
    a_grav = 9.81;

    power_gw = head * mass_rate * eta * a_grav * 1e-9;
end