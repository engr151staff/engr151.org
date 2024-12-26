function wave = play_note(frequency) 
    duration = 1;
    sf = 1 / 8192;
    t = 0:sf:duration;
    wave = sin(2 * pi * frequency * t);
    sound(wave);
end