 #include "Pelota.h"

    Pelota::Pelota(){
        tamanio = 2;
        color.set(255,255,255);

        //pos.set( ofGetWindowWidth()*0.5 , ofGetWindowHeight()*0.5 );


        alphaF = 1;
        escalaF = 1;
        t = 0.0;

        dx0 = 0; dy0 = 0;
        a1 = 0 ; b1 = 0;c1 = 0; d1 = 0; e1=0; tau1= 1; in1 = 0;
        a2 = 0 ; b2 = 0; c2 = 0; d2 = 0; e2=0; tau2= 1; in2 = 0;
        dt = 0.01;
        //cout << "cc"<< endl;W
        vida = 1000;
        tol = 0.000001*dt;
    }

    void Pelota::update(){

        tbuf = t;
        Xbuf = pos.x;
        Ybuf = pos.y;
        x = pos.x;
        y = pos.y;

        //cout << t << "\t"<< pos.x<< "\t"<<pos.y << endl;

        dX = (dx0 + a1*Xbuf + b1*Ybuf  + c1*Xbuf*Xbuf + d1*Ybuf*Ybuf + e1*Xbuf*Ybuf)/tau1 + in1;
        dY = (dy0 + a2*Xbuf + b2*Ybuf  + c2*Xbuf*Xbuf + d2*Ybuf*Ybuf + e2*Xbuf*Ybuf)/tau2 + in2;

        //cout << "D" << "\t"<< dX<< "\t"<< dY << endl;

        kx1 = dt*dX;
        ky1 = dt*dY;

        //cout << "K" << "\t"<< kx1< "\t"<< ky1 << endl;
        //cout << "K" << "\t"<< kx1 << "\t"<< ky1 << endl;

        tbuf = t + 0.5*dt;

        Xbuf = x + 0.5*kx1;
        Ybuf = y + 0.5*ky1;

        dX = (dx0 + a1*Xbuf + b1*Ybuf  + c1*Xbuf*Xbuf + d1*Ybuf*Ybuf + e1*Xbuf*Ybuf)/tau1 + in1;
        dY = (dy0 + a2*Xbuf + b2*Ybuf  + c2*Xbuf*Xbuf + d2*Ybuf*Ybuf + e2*Xbuf*Ybuf)/tau2 + in2;

        kx2 = dt*dX;
        ky2 = dt*dY;

        Xbuf = x + 0.5*kx2;
        Ybuf = y + 0.5*ky2;

        dX = (dx0 + a1*Xbuf + b1*Ybuf  + c1*Xbuf*Xbuf + d1*Ybuf*Ybuf + e1*Xbuf*Ybuf)/tau1 + in1;
        dY = (dy0 + a2*Xbuf + b2*Ybuf  + c2*Xbuf*Xbuf + d2*Ybuf*Ybuf + e2*Xbuf*Ybuf)/tau2 + in2;

        kx3 = dt*dX;
        ky3 = dt*dY;

        tbuf = t + dt;
        Xbuf = x + kx3;
        Ybuf = y + ky3;

        dX = (dx0 + a1*Xbuf + b1*Ybuf  + c1*Xbuf*Xbuf + d1*Ybuf*Ybuf + e1*Xbuf*Ybuf)/tau1 + in1;
        dY = (dy0 + a2*Xbuf + b2*Ybuf  + c2*Xbuf*Xbuf + d2*Ybuf*Ybuf + e2*Xbuf*Ybuf)/tau2 + in2;

        kx4 = dt*dX;
        ky4 = dt*dY;

        x = x + (kx1 + 2*kx2 + 2*kx3 + kx4)/6;
        y = y + (ky1 + 2*ky2 + 2*ky3 + ky4)/6;

        absVel = ((pos.x-x)*(pos.x-x)+(pos.y-y)*(pos.y-y));
        if ( absVel < tol*ofRandom(0,100))
            vida = 0;
        //else if (ofRandom(0,100)<2)
         //   vida = 0;

        color.setHsb(absVel*10000.0,255.0,255.0,255.0);
        escalaF = 1.0/(absVel*50+0.15);

        pos.set(x,y);

        t = tbuf;


    }


    void Pelota::agregarFuerza(ofVec2f fuerza){
        in1 = 0;//fuerza.x;
        in2 = 0;//fuerza.y;
    }


    void Pelota::draw(){
        if (vida)
        {
        ofSetColor(color, color.a * alphaF );
        ofCircle((pos.x+2)/4*ofGetWindowWidth(), (pos.y+2)/4*ofGetWindowHeight(), tamanio * escalaF );
        }
    }

    bool Pelota::pasoElBorde(){
        bool rta = false;

        if ( pos.x < -2 || pos.y < -2 || pos.x > 2 || pos.y > 2)
            rta = true;

        return rta;
    }

    bool Pelota::estaViva(){
        bool rta = true;

        if (vida <= 0)
            rta = false;

        return rta;
    }
