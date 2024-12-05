function run() {
    Java.perform(() => {
      var MainActivity = Java.use('com.example.break_all_ctf_2.MainActivity')
      MainActivity.onCreate.overload('android.os.Bundle').implementation = function(a) {
        console.log('MainActivity onCreate')
        this.onCreate.call(this, a)

        var flag = this.flag()
        console.log('flag:', flag)
      }
    })
}
  
setImmediate(run)