function [wave] = play_notes(notes)
    note_names = ["C", "D", "E", "F", "G", "A", "B"];
    note_freqs = [261.63, 293.66, 329.63, 349.23, 392.00, 440.00, 493.88];
    wave = [];
    t = 0:1/8192:1;
    for k = 1:length(notes)
        index = find(note_names == notes(k));
        f = note_freqs(index);
        note = sin(2 * pi * f * t);
        wave = [wave, note, 0 * t];
        sound(note);
        pause(2);
    end
end