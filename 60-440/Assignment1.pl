graph([[a, b, c], [b, c, e], [c, b, a]]).

list2Pairs([],[]).
list2Pairs([Sub|List],[Sp|Pairs]):- 
    	createPairs(Sub,Sp),
    	list2Pairs(List,Pairs).

createPairs([X|Sub],Pairs):-
    addPairs(X,Sub,Pairs).

addPairs(_,[],[]).
addPairs(First,[X|Sub],[(First,X)|Pairs]):-
    addPairs(First,Sub,Pairs).	

pairs2List([],[]).
pairs2List([(V2,V1)|Pairs],[[V1|Sub]|List]):-
    merge(V1,[(V2,V1)|Pairs],Sub),
    pairs2List(Pairs,List).

merge(_,[],[]).
merge(Search,[(V2,V1)|Pairs],[V2|List]):-
    Search==V1,
    merge(Search,Pairs,List).
merge(Search,[(_,V1)|Pairs],List):-
    Search\=V1,
    merge(Search,Pairs,List).

removeDup([],[],_).
removeDup([[F|_]|Xs],R,Last):-
    Last==F,
    removeDup(Xs,R,F).
removeDup([[F|X]|Xs],[[F|X]|R],Last):-
    Last\=F,
    removeDup(Xs,R,F).

result(Y):-
    	graph(Graph),
    	list2Pairs(Graph,X),%convert the list to pairs
    	flatten(X,Rtn), 	%flatten list of lists of pairs to list of pairs
		pairs2List(Rtn,YY), %undo the conversion from pairs to list
		sort(YY,TT), 		%sort the list
		removeDup(TT,Y,9).	%remove the sublists
