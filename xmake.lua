add_requires("doctest")

option("has_clang")
    set_default(false)
    set_showmenu(false)
    before_check(function (option)
        import("lib.detect.find_program")
        if find_program("clang++") then
            option:enable(true)
        end
    end)
option_end()

if has_config("has_clang") then
    set_toolchains("clang")
end

set_languages("c++20")
set_warnings("all", "extra")
add_cxflags("-Werror", "-pedantic-errors")

for _, dir in ipairs(os.dirs("*")) do
    local test_file = path.join(dir, "test.cpp")
    if os.isfile(test_file) then
        target(dir)
            set_kind("binary")
            set_default(false)
            add_files(test_file)
            add_packages("doctest")
            add_tests("default")
    end
end
