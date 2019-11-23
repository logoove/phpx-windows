namespace Fun;
class Fun{
//打印变量
public static function dump(t){
 echo  "<pre>".print_r(t,true)."</pre>";
}
//输出json
public static function json(int code=200,string message="请求成功",var list=[],var total=0){
var json1;
let json1 =["code":code,"message":message];
if (!empty(list)) {
    let   json1["list"] = list;
        }
        if (!empty(total)) {
   let   json1["total"] = total;
        }
        header("Content-type: application/json");
       exit(json_encode(json1,JSON_UNESCAPED_UNICODE));
}
}
