function [B] = calculateBmis(W, H)
    % Convert weight matrix from pounds to kilograms
    W = W ./ 2.205;
    % Convert height matrix from feet to meters
    H = H ./ 3.281;
    % Calculate BMIs
    B = W ./ H.^2;
end