add_rules("mode.debug", "mode.release")

rule("EasyX")
    on_load(function (target)
        target:add("includedirs", "thirdparty/easyx/include")
        if is_arch("x86") then
            target:add("linkdirs", "thirdparty/easyx/x86")
        elseif is_arch("x64") then
            target:add("linkdirs","thirdparty/easyx/x64")
        end
    end)

target("PlantVsPlant")
    set_kind("binary")
    add_files("src/**.cpp")
    add_headerfiles("src/**.h")
    add_includedirs("src")
    add_rules("EasyX")
    add_syslinks("kernel32", "user32", "gdi32", "winspool", "comdlg32", 
                 "advapi32", "shell32", "ole32", "oleaut32", "uuid", 
                 "odbc32", "odbccp32")
    set_rundir("$(projectdir)")