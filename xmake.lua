add_rules("mode.debug", "mode.release")

add_defines("DEBUG")
add_includedirs(".")
set_languages("cxx17")


local project_name           = "test"
local target_output          = "D:/SystemCache/SystemRsourceDirectory/Desktop"
local kernel_header_file_dir = "I:/Windows Kits/10/Include/**"

target(project_name)
    -- base setting
    add_rules("mode.debug")
    add_rules("wdk.env.kmdf", "wdk.driver")
    add_values("wdk.tracewpp.flags", "-func:TraceEvents(LEVEL,FLAGS,MSG,...)", "-func:Hexdump((LEVEL,FLAGS,MSG,...))")
    add_files("sys/*.cpp", {rule = "wdk.tracewpp"})
    set_policy("build.c++.modules", true)

    --  add kernel header file dir
    add_includedirs(os.dirs(kernel_header_file_dir))

    -- must use admin to execute the command "xmake l utils.wdk.testcert install" once
    -- sign driver for test
    add_rules("hook.sign")
    set_values("wdk.sign.mode", "test")

    -- support version system
    set_values("wdk.env.winver", "win10")
    set_values("wdk.env.winver", "win10_rs3")
    -- set_values("wdk.env.winver", "win81")
    -- set_values("wdk.env.winver", "win8")
    set_values("wdk.env.winver", "win7")
    set_values("wdk.env.winver", "win7_sp1")
    set_values("wdk.env.winver", "win7_sp2")
    set_values("wdk.env.winver", "win7_sp3")

rule("hook.sign")
    add_deps("wdk.driver", "wdk.env.wdm",{order = true})
    after_build(function (target)
        os.cp(target:targetfile(),target_output)
    end)

target("app")
    add_rules("mode.debug")
    add_rules("wdk.binary")
    add_files("exe/*.cpp")