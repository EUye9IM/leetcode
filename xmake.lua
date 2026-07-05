option("has_clang")
set_default(false)
set_showmenu(false)
before_check(function(option)
    import("lib.detect.find_program")
    if find_program("clang++") then
        option:enable(true)
    end
end)
option_end()

if has_config("has_clang") then
    set_toolchains("clang")
end

local has_cpp = false
for _, dir in ipairs(os.dirs("*")) do
    if os.isfile(path.join(dir, "main.cpp")) then
        has_cpp = true
        break
    end
end

if has_cpp then
    add_requires("doctest")
end

local language_specs = {
    { file = "main.cpp", lang = "cpp", suffix = "" },
    { file = "main.go",  lang = "go",  suffix = "" },
    { file = "main.rs",  lang = "rs",  suffix = "" },
}

for _, dir in ipairs(os.dirs("*")) do
    for _, spec in ipairs(language_specs) do
        local file = path.join(dir, spec.file)
        if os.isfile(file) then
            target(dir .. spec.suffix)
            set_kind("binary")
            set_default(false)
            add_files(file)
            if spec.lang == "cpp" then
                set_languages("c++20")
                set_warnings("all", "extra")
                add_cxflags("-Werror", "-pedantic-errors")
                add_packages("doctest")
            end
            add_tests("default")
        end
    end
end
