//some constants
fn_hub = 50;
fn_outline = 200;

//the middle part of the bike wheel
module hub(){
    rotate(a=270,v=[1,0,0]){
        cylinder(h=5, r=.7, center=true, $fn=50);
        translate([0,0,.6])cylinder(.1,1,true,$fn=fn_hub);
        translate([0,0,-.6])cylinder(.1,1,true,$fn=fn_hub);
    }
}

//just arranges the spokes attached to the hub
module arrange_spoke(){
    //centered both spokes for simplicity
    for(i=[0:4]){
        rotate( i*360/7, [0, 1, 0])
   translate( [0, .2, 0] )cylinder(h=38,r = .2,center=true);
    }
    
    for(i=[0:4]){
        rotate( i*360/6, [0, 1, 0])
   translate( [0, -.2, 0] ) cylinder(h=38,r = .2,center=true);
    } 
}

//makes the rim of the wheel
module outline(){
        rotate (a=270, v=[1,0,0]) {
            //applies the features of the sphere to the rim of wheel, very expensive
            // trying to make the wheels look more smooth and tire-like
            minkowski(){
                //creates the tire shape by taking the difference between two cylinders
                difference () {
            cylinder (h=1.5, r=20, center=true,$fn=fn_outline);
            cylinder(h=3, r=19, center=true, $fn=fn_outline);
            }
                sphere(.50);
            }  
        }
}

//Just puts the individual parts together
//I just wanted to organize the parts separately first
//final call to make the full wheel
module wheel(){
    hub();
    outline();
    arrange_spoke();
}

//makes it less repetitive
module frame_part(a, x1, y1, z1, x2, y2, z2, h, r, c=false){
    rotate(a, [x1,y1,z1]){
        translate([x2,y2,z2])cylinder(h, r, center=c);
    }
}

//bike frame
module frame(){
    //front wheel stuff
    frame_part(20, 0, 1, 0, 0, -2, 0, 50, .8);
    frame_part(20, 0, 1, 0, 0, 2, 0, 50, .8);
   frame_part(270, 1,0,0, 17, -46.5, 0, 20, .8, true); 
    frame_part(270, 1,0,0, 13, -35, 0, 5, .8, true);
    
    //rod connecting to wheel
    frame_part(90, 0, 1, 0, -34.7, 0, 13, 53, .8);
    
    //rod connecting to pedal and support
    frame_part(270, 1,0,0, 9, -23.5, 0, 5, .8, true);
    frame_part(115, 0, 1, 0, -25, 0, -2, 50, .8);
    
    //back wheel to pedal
    frame_part(275, 0, 1, 0, 8 , -2 , -89,35 ,.8);
    
    //bike rod to pedal
    frame_part(20, 0, 1, 0, 50, 0, 20, 45, .8);
    
    
    frame_part(90, 0, 1, 0, -3, -10, 53.5, 13, .8);
    frame_part(90, 0, 1, 0, -3, 10, 42, 13, .8);
    
    frame_part(270, 1, 0, 0, 54, -3, 0, 20, .8, true);
    //I realized I did something wrong with the whole frame_part module but it was very last minute so I just remade the translation
    
    //support and back wheel rods to sets rod
    frame_part(270, 1,0,0, 64.5, -31, 0, 5, .8, true); 
    translate([90,-2,0])rotate(320, [0,1,0])cylinder(40.5, .8);
    
    translate([90,2,0])rotate(320, [0,1,0])cylinder(40.5, .8);
    
    //very bad seat
    translate([69,0,43])cylinder(2, 5, 10);
}




module bike(){
    frame();
    wheel();
    translate([90,0,0])wheel();
}

bike();