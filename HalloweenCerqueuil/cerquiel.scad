
r=3;
margin = 1;
points=[
	[49/2  -r-margin, 169  -r-margin], 
	[88.5/2-r-margin, 115.6 ],
	[33/2  -r-margin, 0    +r+margin]];
h=28;

difference() {
	base(r);
	translate([0,0,2]) 
		base(r-1.2);
}

module base(r) {
	hull() 
		for (i=[0:2]) {
			x=points[i][0];
			y=points[i][1];
			translate([x,y,0])
				cylinder(h,r,r,$fn=32);
			translate([-x,y,0])
				cylinder(h,r,r,$fn=32);
		}
}