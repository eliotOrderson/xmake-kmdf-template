add_rules("mode.debug", "mode.release")

set_languages("cxx17")
add_defines("DEBUG")
add_includedirs(".")

local driver_name       = "test"
local target_output     = "D:/SystemCache/SystemRsourceDirectory/Desktop/sign"
local kernel_header_dir = "I:/Windows Kits/10/Include/**"

target(driver_name)
    -- base setting    
    add_rules("wdk.env.kmdf", "wdk.driver")
    add_values("wdk.tracewpp.flags", "-func:TraceEvents(LEVEL,FLAGS,MSG,...)", "-func:Hexdump((LEVEL,FLAGS,MSG,...))")
    add_files("driver/*.cpp", {rule = "wdk.tracewpp"})

    --  add kernel header file dir
    add_includedirs(os.dirs(kernel_header_dir))

    -- sign driver for test
    -- add_rules("wdk.driver", "wdk.env.wdm")
    -- set_values("wdk.sign.mode", "test")

    -- support version system
    set_values("wdk.env.winver", "win10")
    set_values("wdk.env.winver", "win10_rs3")    

    -- copy target file to signature directory  
    after_build(function (target) 
        os.cp(target:targetfile(),target_output)
    end)

