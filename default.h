	"",
	"cmdmap : entry :",
	"cmdmap <Tab> pass",
	"cmdmap ; entry ;",
	"cmdmap / entry /",
	"cmdmap ? entry ?",
	"cmdmap [[ go prev",
	"cmdmap ]] go next",
	"cmdmap r reload",
	"cmdmap R reload!",
	"cmdmap <space> scroll +1p",
	"cmdmap <Page_Down> scroll +1p",
	"cmdmap <C-f> scroll +1p",
	"cmdmap <Page_Up> scroll -1p",
	"cmdmap <C-b> scroll -1p",
	"cmdmap <Up> scroll -1",
	"cmdmap k scroll -1",
	"cmdmap <Down> scroll +1",
	"cmdmap j scroll +1",
	"cmdmap <Home> scroll 0",
	"cmdmap gg scroll 0",
	"cmdnmap gg scroll %ip",
	"cmdmap <End> scroll 32768p",
	"cmdmap G scroll 32768p",
	"cmdnmap G scroll %ip",
	"cmdmap <BackSpace> go back",
	"cmdmap H go back",
	"cmdmap L go forth",
	"cmdmap p paste",
	"cmdmap P tabpaste",
	"cmdmap y yank",
	"cmdmap n next",
	"cmdmap N next!",
	"cmdmap t entry \":tabnew \"",
	"cmdmap o entry \":open \"",
	"cmdmap T js 'command(\"entry\", \":tabnew \" + window.location)'",
	"cmdmap O js 'command(\"entry\", \":open \" + window.location)'",
	"cmdmap f entry ;f",
	"cmdmap F entry ;F",
	"cmdmap i insert",
	"cmdmap u undo",
	"cmdmap d q",
	"cmdmap D js 'var i = Number(command(\"get\", \"widget\", \"tabs\", \"page\")); command(\"widget\", \"tabs\", \"page\", String(i - 1)); command(\"killtab\", String(i));'",
	"cmdmap gt action TabNext",
	"cmdmap <C-n> action TabNext",
	"cmdmap <C-Tab> action TabNext",
	"cmdnmap gt widget tabs page %i",
	"cmdmap gT action TabPrevious",
	"cmdmap <C-p> action TabPrevious",
	"cmdmap g0 widget tabs page 0",
	"cmdmap g$ widget tabs page -1",
	"cmdmap <CR> submit",
	"cmdmap <C-c> action Stop",
	"",
	"cmdmap gp action Preferences",
	"cmdmap gs action ManageSearchEngines",
	"",
	"cmdmap bm action Menubar",
	"cmdmap bn action Navigationbar",
	"cmdmap bb action Bookmarkbar",
	"",
	"{{{",
	"	jscmd scroll '",
	"		var vert = (args[0] != \"h\");",
	"		var num = vert ? args[0] : args[1];",
	"		if (!num)",
	"			throw(\"scroll: too few arguments\");",
	"		if (!window.scrollthing) {",
	"			window.scrollthing = document.body;",
	"		}",
	"		var pagesize = 20;",
	"		if (num.substr(-1) == \"p\") {",
	"			if (window.scrollthing == document.body) {",
	"				pagesize = (vert ? window.innerHeight : window.innerWidth) * 0.9;",
	"			}",
	"			num = num.substr(0, num.length - 1);",
	"		}",
	"		var pos = vert ? window.scrollthing.scrollTop : window.scrollthing.scrollLeft;",
	"		if (num.substr(0, 1) == \"+\")",
	"			pos += Number(num.substr(1)) * pagesize;",
	"		else if (num.substr(0, 1) == \"-\")",
	"			pos -= Number(num.substr(1)) * pagesize;",
	"		else",
	"			pos = Number(num) * pagesize;",
	"		if (vert)",
	"			window.scrollthing.scrollTop = pos;",
	"		else",
	"			window.scrollthing.scrollLeft = pos;",
	"	'",
	"}}}",
	"",
	"{{{",
	"	jscmd js_paste '",
	"		var el = document.activeElement;",
	"		if (el) {",
	"			var ss = el.selectionStart;",
	"			el.value = el.value.substring(0, el.selectionStart) + args[0] + el.value.substring(el.selectionEnd);",
	"			el.selectionStart = el.selectionEnd = ss + args[0].length;",
	"		}",
	"	'",
	"}}}",
	"",
	"",
	"set hintstyle \"background-color: #59FF00; border: 2px solid #4A6600; color: black; font-size: 9px; line-height: 9px; font-weight: bold; margin: 0px; padding: 1px; z-index: 1000; border-radius: 6px;\"",
	"set hint_default \"a.href input select textarea button .onclick\"",
	"set hint_tabnew a.href",
	"set hint_yank \"a.href a.name\"",
	"",
	"set go_next \"^>$, ^>>$, ^>>>$, ^next$, next *[>»], ^далее, ^след[.у], next, >\"",
	"set go_prev \"^<$, ^<<$, ^<<<$, ^prev$, ^previous, prev[.]? *[<«], previous *[<«], ^назад, ^пред[.ы], previous, <\"",
	"",
	"set paste_primary 1",
	"",
	"source ~/.midoratorrc",
	"",
