struct pt {
  ll x, y;
};

pt Ori = pt{0, 0};

// Vector Oa -> Ob
ll cross(pt a, pt b, pt O){
  return a.x*(b.y-O.y)+b.x*(O.y-a.y)+O.x*(a.y-b.y);
}

int orientation(pt a, pt b, pt O) {
  ll v = cross(a, b, O);
  if (v < 0) return -1; // clockwise
  if (v > 0) return +1; // counter-clockwise
  return 0;
}

bool firstHalf(pt a){
  int o = orientation(pt{1, 0}, a, pt{0, 0});
  if(o == 0) o = a.x > 0 ? 1 : -1;
  return o > 0;
}

bool comp(pt &a, pt &b){
  if(firstHalf(a) == firstHalf(b)) return cross(a, b, Ori) > 0;
  return firstHalf(a);
}