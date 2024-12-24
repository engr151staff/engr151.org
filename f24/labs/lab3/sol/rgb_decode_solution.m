%read image
pic = imread('color_code_rgb.png');

%plot original
subplot(2,1,1);
imshow(pic);

%logical arrays for 3 wanted colors
is_red = pic(:,:,1)>3*pic(:,:,2) &...
    pic(:,:,1)>3*pic(:,:,3);
is_green = pic(:,:,2)>3*pic(:,:,1) &...
    pic(:,:,2)>3*pic(:,:,3);
is_blue = pic(:,:,3)>3*pic(:,:,1) &...
    pic(:,:,3)>3*pic(:,:,2);

%logical array for any of 3 wanted colors
color_bool = is_red | is_green | is_blue;

%make 3 layers of array
bool_3D = cat(3,color_bool,color_bool,color_bool);

%apply logical array to image
pic(~bool_3D) = 255; %make other pixels white

subplot(2,1,2);
imshow(pic);
imwrite(pic, 'decoded_message.jpg');
