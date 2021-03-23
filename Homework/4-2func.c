
/*  probID: W4-2-Expression  */
//
//n 為運算式的 token 數量 (同時也是傳入的三個陣列 type, integers, symbols 的長度)
//type[ ] 是各個 token 的型態，其中 0 代表該位置為整數 token，1 代表為運算子 token
//integers[ ] 陣列為各個整數 token 的值
//symbols[ ] 陣列為運算子 token
struct binary_operator_priority{
    int pos; // in symbols[pos]

    int bracket; // smaller, higher
    int type; // +-0 , */1
};

struct binary_operator_priority max(struct binary_operator_priority a,struct binary_operator_priority b){
    if( a.bracket < b.bracket )
        return a;
    else if( a.bracket == b.bracket ){
        if(a.type < b.type)
            return a;
        else
            return b;
    }
    else
        return b;
}



int combine(int a,int b,char binary_operator){
    switch(binary_operator){
    case '+':
        return a+b;
        break;
    case '-':
        return a-b;
        break;
    case '*':
        return a*b;
        break;
    case '/':
        return a/b;
        break;
    default :
        return 0;
        break;
    }
}

int only_one_integer(int n,int type[]){
    int count = 0;
    for(int i=0;i<n;i++){
        if(type[i]==0){
            count++;
        }
    }
    if(count == 1)
        return 1;
    else
        return 0;
}
int find_binary_operator(int n,int type[],char symbols[]){
    struct binary_operator_priority a,b;
    int envir_bracket = 0;
    int initialized = 0;

    for(int i=0;i<n;i++){
        if(type[i]==1){
            if(symbols[i]==';')
                continue;
            if(symbols[i]=='('){
                envir_bracket ++;
                continue;
            }
            if(symbols[i]==')'){
                envir_bracket --;
                continue;
            }
            if(initialized){
                b.bracket = envir_bracket;
                b.pos = i;
                if( symbols[b.pos]=='*'||symbols[b.pos]=='/') b.type =1;
                else b.type = 0;
//                printf("b.bracket ==%d, b.pos ==%d, b.type == %d\n",b.bracket,b.pos,b.type);
                a = max(a,b);
                continue;
            }
//            initialize a
            if(initialized == 0){
            a.bracket = envir_bracket;
            a.pos = i;
            if( symbols[a.pos]=='*'|| symbols[a.pos]=='/') a.type = 1;
            else a.type = 0;
//            printf("initial a: a.bracket ==%d, a.pos ==%d, a.type ==%d\n",a.bracket,a.pos,a.type);
            initialized = 1;
            }
        }
    }
//    printf("bi_op is %c,which means bi_op bracket:%d and pos:%d and type:%d \n",symbols[a.pos],a.bracket,a.pos,a.type);
    return a.pos;
}

int expr_evaluation(int n,int type[],int integers[],char symbols[]){
    if( only_one_integer(n,type))
        for(int i=0;i<n;i++){
            if(type[i]==0)
                return integers[i];
        }
    int binary_operator_pos = find_binary_operator(n,type,symbols);

    int left_n = binary_operator_pos ;

    int right_n = n - left_n - 1;

    return combine( expr_evaluation(left_n,type,integers,symbols),
                    expr_evaluation(right_n,&type[binary_operator_pos+1],&integers[binary_operator_pos+1],&symbols[binary_operator_pos+1]),
                   symbols[binary_operator_pos]);
}
