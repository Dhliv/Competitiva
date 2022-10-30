const ld EPSILON = 0.000001;

struct pt{
  ld x, y;
};

int orientation(pt &a, pt &b, pt &c){
  ld A, B, C;
  A = -(b.y - a.y);
  B = b.x - a.x;
  C = b.y*a.x - a.y*b.x;

  ld result = A*c.x + B*c.y + C;
  if(result > 0.0) return 1; // Clockwise;
  if(result < 0.0) return -1; // Counter-clockwise;
  return 0; // Collinear.
}

bool coord_in_bounds(ld x, ld y, ld a){
  ld mini, maxi;
  mini = min(x, y);
  maxi = max(x, y);

  return (a + EPSILON >= mini and a - EPSILON <= maxi);
}

bool point_in_segment(pt &a, pt &b, pt &c){
  ld A, B, C;
  A = -(b.y - a.y);
  B = b.x - a.x;
  C = b.y*a.x - a.y*b.x;

  ld result = A*c.x + B*c.y + C;
  if(fabs(result) < EPSILON){
    if(coord_in_bounds(a.x, b.x, c.x) and coord_in_bounds(a.y, b.y, c.y)) return true;
  }

  return false;
}

bool lines_intersect(pt &a, pt &b, pt &c, pt &d){
  int o1, o2, o3, o4;
  o1 = orientation(a, b, c);
  o2 = orientation(a, b, d);
  o3 = orientation(c, d, a);
  o4 = orientation(c, d, b);

  if(o1 != o2 and o3 != o4) return true;

  if(o1 == 0 and point_in_segment(a, b, c)) return true;
  if(o2 == 0 and point_in_segment(a, b, d)) return true;
  if(o3 == 0 and point_in_segment(c, d, a)) return true;
  if(o4 == 0 and point_in_segment(c, d, b)) return true;

  return false;
}

bool point_in_polygon(pt &P, vector<pt> &pts){
  pt aux = pt{INF, P.y};
  int intersections = 0, duplicatedIntersections = 0;

  FOR(i, 0, pts.size()){
    pt &p1 = pts[i];
    pt &p2 = pts[(i + 1)%pts.size()];

    // Projected line pass across one point.
    if(fabs(P.y - p1.y) < EPSILON and P.x - EPSILON < p1.x) duplicatedIntersections++;

    intersections += lines_intersect(P, aux, p1, p2);
  }

  return (intersections - duplicatedIntersections) & 1;
}