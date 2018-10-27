color(blue).
color(red).
color(purple).
verticies([a,b,c,d,e,f]).
edges([
      (a,b),
      (a,c),
      (a,d),
      (a,f),
      (b,c),
      (b,e),
      (b,f),
      (c,d),
      (c,e),
      (d,e),
      (d,f),
      (e,f)
]).

%Generates and tests initial set
result(Result):-
   verticies(Vs),
   edges(Es),
   applyColors(Vs,Result),
   checkColors(Es,Result).
   
%Sequence through all verticies and apply any color
applyColors([],[]).
applyColors([Vert|Vs],[Vert-Color|T]):-
   color(Color),
   applyColors(Vs,T).
   
%Validates all colors to ensure connecting verticies do not have the same coloring
checkColors([],_).
checkColors([(V1,V2)|Edges],Result):-
   member(V1-C1,Result), 
   member(V2-C2,Result), 
   C1\=C2,                 
   checkColors(Edges,Result).
