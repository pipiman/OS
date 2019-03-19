
     Mat imgL = Mat(src, Rect(0, 0, wid / 2, hei));
     Mat imgR = Mat(src, Rect(wid / 2, 0, wid / 2, hei));

     transpose(imgL, imgL);
     flip(imgL, imgL, 1);
     transpose(imgR, imgR);
     flip(imgR, imgR, 0);





