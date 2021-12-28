/* $Id: t32report.js 14729 2019-07-31 14:36:13Z csax $ */

function fixOldIE(){
	if ($('#IE8').length){
		/* Help IE8, which does not know ":last-child" CSS selector */
		$('table tr:last-child, table th:last-child, table td:last-child, ul li:last-child').addClass("last-child");

		for (var i=7; i<12; i++){
			$('table.t32-coverage tr :nth-child(' + i +')').addClass("child"+i);
		}
		$('body').addClass("IE8");
	}
}

var gAddrWidth = 8;
var gFileExt = ".xml";

var showDecisions = true;

function GetParam(name){
	var regex = new RegExp("[?&]"+name+"=([^&#]*)");
	var result = regex.exec( window.location.href );
	if (!result)
		return "";
	return result[1];
}

function updateColorMode(){
	if ($('#cb1').prop('checked')) {
		$('body').removeClass('gray')
	} else {
		$('body').addClass('gray');
	}
}

function updateListMode(){
	switch (getListMode()) {
		case "ASM":
			$('#t32-list').addClass('noHLL').removeClass('noASM');
			break;
		case "HLL":
			$('#t32-list').addClass('noASM').removeClass('noHLL');
			break;
		default:
			$('#t32-list').removeClass('noASM').removeClass('noHLL');
			break;
	}
	
	$("#t32-bookmarks td.bmname a, #t32-bookmarks td.remark a",this).off('click');
		if($('#t32-list').length == 0) { /* Single file report */
			switch (mode) {
				case "HLL":
					$('#t32-list td.remark.hllonly span.addr').replaceWith(function() {
						var addr = $(this).text();
						var offset = addr.substr(addr.indexOf(':')+1);
						while (offset.charAt(0)=='0')
							offset=offset.substr(1);
						return '<a class="addr" href="#x'+offset+'" title="View '+addr+'">'+$(this).html()+"</a>";
					});
					$('#t32-bookmarks tr').each( function(){
						var lineHref = $("td.line a",this).attr("href");
						if (lineHref){
							$("td.bmname a, td.remark a",this).attr("href",lineHref);
						} else {
							$("td.bmname a, td.remark a",this).on('click', function(){ setListMode("MIX"); });
						}
					});
					$('.addr a').on('click', function(evt){ setListMode("MIX"); }); /* switch to MIX mode if s.o. clicks on an address link */
					$('#t32-list td.remark.hllonly a.addr').on('click', function(evt){
						var row = $(this).parent().parent();
						var oldpos = row.offset().top;
						var id = "#"+row.attr("id");
						setListMode("MIX");
						var newpos = $(id).offset().top;
						var delta = newpos - oldpos;
						$(document).scrollTop( $(document).scrollTop() + delta );
						evt.preventDefault();
						return false;
					});
					break;
				case "ASM":
				default:
					$('#t32-bookmarks tr').each( function(){
						var addrHref = $("td.addr a",this).attr("href");
						if (addrHref){
							$("td.bmname a, td.remark a",this).attr("href",addrHref);
						} else {
							$("td.bmname a, td.remark a",this).on('click', function(){ setListMode("MIX"); });
						}
					});
					$('.addr a').off('click');
					$('#t32-list td.remark.hllonly a.addr').off('click');
					break;
			}
		}
}

function setListMode(mode){
	if (mode!="ASM" && mode!="HLL"){
		mode="MIX";
	}
	if (getListMode() != mode){
		$('#footer input[name=listmode]').prop('checked',false);
		$('#footer input[name=listmode][value='+mode+']').prop('checked',true);
		updateListMode();
	}
}

function getListMode(){
	return $('#footer input[name=listmode]:checked').val();
}



function makeTableSortable($table){
	if ($('tbody tr',$table).length < 2)
		return;

	$table.addClass("sortable");
	$('th',$table).click(function(){
		var table = $(this).parents('table').eq(0);
		var col = $(this).index();
		var rows = table.find('tr:gt(0)').toArray().sort(comparer(col));
		var asc = $(this).hasClass("ascending");
		asc = !asc; // if it is already ascending make it descending
		if (!asc){
			rows = rows.reverse();
		}
		for (var i = 0; i < rows.length; i++){
			table.append(rows[i]);
		}
		$('th',$table).removeClass("ascending descending");
		$(this).addClass(asc ? "ascending" : "descending");

		if ($('#IE8').length){
			$('tr',table).removeClass("last-child");
			$('tr:last-child',table).addClass("last-child");
		}
	})
}
function comparer(index) {
	return function(a, b) {
		var valA = getCellValue(a, index);
		var valB = getCellValue(b, index);
		return $.isNumeric(valA) && $.isNumeric(valB) ? valA - valB : valA.localeCompare(valB);
	}
}
function getCellValue(row, index){
	return $(row).children('td').eq(index).text();
}


function zeroPadAddress(addr){
	return ("0000000000000000"+addr).slice(-gAddrWidth);
}

function beautifyAdresses() {
	/* get address width (in nibbles) */
	gAddrWidth = 0;
	$('td.addr, span.addr').each(function(index) {
		var re = /:([0-9a-f]+:)([0-9a-f]+)(--)?([0-9a-f]+:)?([0-9a-f]+)?/i;
		var addrStr = $(this).text();
		var arr;
		if ((arr = re.exec(addrStr)) !== null) {
			var toStr = arr[arr.length - 1];
			if (toStr){
				var s = toStr.length;
				if (s > gAddrWidth && s <= 16)
					gAddrWidth = s + s%2;
			}
		}
	});
	if (!gAddrWidth)
		gAddrWidth = 8;

	/* pad adresses with zeroes */
	$('td.addr, span.addr').each(function(index) {
		var re = /([a-z]+:)0*([0-9a-f]+:)?0*([0-9a-f]+)(--)?([0-9a-f]+:)?0*([0-9a-f]+)?/i;
		var addrStr = $(this).text();
		var arr;
		if ((arr = re.exec(addrStr)) !== null) {
			var memClassStr = arr[1];
			var spaceIdStr = arr[2];
			var fromStr = arr[3];
			var toStr = arr[arr.length - 1];

			fromStr = fromStr ? (zeroPadAddress(fromStr)) : "";
			toStr = toStr ?  ('--' + zeroPadAddress(toStr)) : "";
			if (spaceIdStr) {
				fromStr = spaceIdStr + fromStr;
			}
			if (fromStr || toStr)
				$(this).html( memClassStr + fromStr + toStr );
		}
	});
}

function addAddrLinks(index) {  /* add address links */
			var re = /([a-z]+:)(0x)?([0-9a-f]+)/i;
			var arr;
			if ((arr = re.exec( $(this).text() )) !== null) {
				var memClassStr = arr[1];
				var fromStr = arr[3];

				var from = '#x' + parseInt(fromStr,16).toString(16).toUpperCase();
				if($(from).length != 0){
					fromStr = '<a href="' + from + '">' + fromStr + '</a>';
				}
				$(this).html( memClassStr + fromStr );
			}
		}
		
function addAddrLinksRange(index) {  /* add address links for address ranges */
	var re = /([a-z]+:)(0x)?([0-9a-f]+)--(0x)?([0-9a-f]+)/i;
	var arr;
	if ((arr = re.exec( $(this).text() )) !== null) {
		var memClassStr = arr[1];
		var fromStr = arr[3];
		var toStr   = arr[5];

		var from = '#x' + parseInt(fromStr,16).toString(16).toUpperCase();
		fromStr = zeroPadAddress(fromStr);
		if($(from).length != 0){
			fromStr = '<a href="' + from + '">' + fromStr + '</a>';
		}

		toStr = zeroPadAddress(toStr);
		var offset = [3,1,7,0,5];
		for (var i = 0; i < offset.length; i++){
			var to = "#x" + (parseInt(toStr,16) - offset[i]).toString(16).toUpperCase();

			if($(to).length != 0){
				toStr = '<a href="' + to + '">' + toStr + '</a>';
				break;
			}
		}
		$(this).html( memClassStr + fromStr + '--' + toStr );
	}
}

function addFileLinks(){
	if ($('#t32-ListModule').length && $('#t32-list').length == 0 && $('#filelist').length == 0){ /* COVerage.ListModule, but not via export_asm_module ? */
		$('#t32-ListModule td.tree').each(function(index) {
			var re = /\\\\(.+?)\\(.+)/;
			var arr;
			if ((arr = re.exec($(this).text())) !== null) {
				var prog = arr[1];
				var module = arr[2];
				if (prog && module && module!="Global"){
					var filename = fix_filename(prog) + '/' + fix_filename(module) +"/Coverage_Report" + gFileExt;
					$(this).html( '<a href="' + filename + '">' + $(this).text() + '</a>');
				}
			}
		});
	}
	if ($('#filelist').length) { /* Single file report */
		$('#t32-ListModule td.tree').each(function(index) {
			var path = window.location.pathname;
			var page = path.split("/").pop();
			var re = /\\\\(.+?)\\(.+)/;
			var arr;
			if ((arr = re.exec($(this).text())) !== null) {
				$(this).html( '<a href="#mf.' + arr[1] + '.' + arr[2] + '">' + $(this).text() + '</a>');
			}
		});
		
		
		$('table.t32-coverage td.addr').each(addAddrLinksRange);
		$('#filelist td.addr').each(addAddrLinks);
		$('#t32-bookmarks td.addr').each(addAddrLinks);
		
		/* duplicate links from bookmark to code listing */
		$('#t32-bookmarks tr').each(function(index) {
			var href = $('td.line a', this).attr('href');
			if (!href)
				href = $('td.addr a', this).attr('href');
			if (href){
				var $bmname = $("td.bmname", this);
				var $remark = $("td.remark", this);

				$bmname.html('<a href="' + href + '">' + $bmname.text() + '</a>' );
				if ($remark.length)
					$remark.html('<a href="' + href + '">' + $remark.text() + '</a>' );
			}
		});
	}
	
	if($('#filelist').length == 0) { /* Multi file report */
		$('#t32-ListFunc tr.function td.tree').each(function(index) {
			var func = $(this).text();
			if (func){
				var filename;

				var uid = $(this).parent().attr('data-uid');
				/* Prefer uid for link generation */
				if (typeof uid == "undefined") {
					filename = "func_" + fix_filename(func) + gFileExt;
				} else {
					filename = "func-" + uid + gFileExt;
					$(this).parent().removeAttr('data-uid');
				}
				$(this).html( '<a href="' + filename + '">' + func + '</a>');
			}
		});
	}
		
	if ($('#t32-ListModule').length || $('#t32-ListFunc').length) { /* COVerage.ListModule or COVerage.ListFunc ? */
		if($('#filelist').length == 0) { /* Multi file report */
			$('#t32-bookmarks td.sym, #t32-bookmarks td.addr').each(function(index) {
				var re = /\\\\(.+?)\\(.+?)\\([^\\]+)(.*)/;
				var sym = $(this).parent().children('.sym');
				var funcUid = sym.attr('data-func-uid');
				var arr;
				if ((arr = re.exec(sym.text())) !== null) {
					var prog = arr[1];
					var module = arr[2];
					var func = arr[3];
					var line = arr[4];
					if (prog && module && func){
						var filename;
						if (typeof funcUid == "undefined") {
							filename = "func_" + fix_filename(func) + gFileExt;
						} else {
							filename = "func-" + funcUid + gFileExt;
						}
						if ($('#t32-ListModule').length) { /* COVerage.ListModule ? */
							filename = fix_filename(prog) + '/' + fix_filename(module) + "/" + filename;
						}
						if ( $(this).hasClass("addr") ){
							var addr = $(this).text();
							$(this).html('<a href="' + filename + '?address=' + addr +'">' + addr + '</a>');
						} else {
							$(this).html('<a href="' + filename + '?anchor=t32-bookmarks">' +
								'\\\\' + prog + '\\' + module + '\\' + func + '</a>' + line);
						}
					}
				}
			});
		}
	}
}

function fix_filename(filename){
	/* replaces /<>:|?*"\ and spaces to underscores */
	return filename.replace(/[\/<>:\|\?\*\"\\ ]/g, "_")
}

function formatTimeStampUTC(unixtime){
	if (isNaN(unixtime))
		return unixtime;
	function pad(x){return (x<10 ? '0'+x : x)};
	var d = new Date(unixtime * 1000);
	var date = d.getUTCFullYear() + '-' + pad(d.getUTCMonth()) + '-' + pad(d.getUTCDate());
	var time = d.getUTCHours() + ':' + pad(d.getUTCMinutes()) + ':' + pad(d.getUTCSeconds());
	var str = date + 'T' + time + 'Z';
	return str;
}

function formatTimeStamp(unixtime){
	if (isNaN(unixtime))
		return unixtime;
	function pad(x){return (x<10 ? '0'+x : x)};
	var d = new Date(unixtime * 1000);
	var date = d.getFullYear() + '-' + pad(d.getMonth()+1) + '-' + pad(d.getDate());
	var time = d.getHours() + ':' + pad(d.getMinutes()) + ':' + pad(d.getSeconds());
	var tz = -d.getTimezoneOffset();
	tz = (tz<0 ? '' : '+') + pad(Math.ceil(tz/60)) + ':' + pad(tz%60);
	var str = date + 'T' + time + tz;
	return str;
}

function fix_id(str){
	var i, arr = [];

	/* ID and NAME tokens must begin with a letter ([A-Za-z]) and may be followed by any number of letters, digits ([0-9]), hyphens ("-"), underscores ("_"), colons (":"), and periods (".") */
	for (i = 0; i < str.length; i++) {
		var c = str.charAt(i);
		if (c == '\\') {
			arr[i] = '.';
		} else if (c == '.') {
			arr[i] = '-';
		} else if (c.search(/[a-z0-9_]/i) >= 0){
			arr[i] = str[i];
		} else {
			arr[i] = ':' + c.charCodeAt().toString(16) + ':';
		}
	}
	return arr.join('');
}

function ImproveDataList(){
	/* mark last HLL line (for CSS) */
	$('#t32-list tr.hll').last().addClass('last_hll');

	/* add IDs and Tooltips for HLL lines */
	$('#t32-list tr.hll td.addr').each(function(index) {
		var module = $(this).parent().data("module");
		var num = $(this).text();
		if (num && module){
			$(this).prop("title", module + "\\" + num);
		}
	});
	$('#t32-list td.remark').append('<a href="#t32-bookmarks" title="to BookMarks">&uArr;</a>');
	$('#t32-list td.remark a').click(function(){return gotoAnchor("t32-bookmarks");});
	$('#t32-list tr:not(.hll)+tr.hll td.code[colspan=4]').append('<a href="#" title="to top">&uArr;</a>');
}

function highlight($element) {
	/* quick higlighting of the target */
	$element.addClass("highlight highlight-peak").delay(200).queue(function(){
		$(this).removeClass("highlight-peak").dequeue();
	}).delay(2100).queue(function(){
		$(this).removeClass("highlight").dequeue();
	});
}

function inViewport(element) {
	if (typeof document.documentElement.getBoundingClientRect == "undefined")
		return false;
	if (typeof jQuery === "function" && element instanceof jQuery)
		element = element.get(0);
	var rect = element.getBoundingClientRect(); /* requires at least IE6/FF3/Safari4/Opera/Chrome */
	return (
		rect.top >= $('#header').outerHeight() &&
		rect.left >= 0 &&
		rect.bottom <= $(window).height() - $('#footer').outerHeight() &&
		rect.right <= $(window).width()
	);
}

function gotoAnchor(Anchor){
	if (!Anchor)
		return true;
	var $target =$('#' + Anchor);
	if (!$target.length)
		return true;
	if (!inViewport($target)){ /* target not completely visible ? */
		$('html, body').scrollTop($target.offset().top - $('#header').outerHeight());
	}
	$('html, body').scrollLeft(0);
	highlight($target);
	return false;
}

function gotoAddress(addr){
	var re = /([a-z]+:)0*([0-9a-f]+:)?0*([0-9a-f]+)(--)?([0-9a-f]+:)?0*([0-9a-f]+)?/i;
	var arr = re.exec(addr);
	if (arr && arr[3]){
		var src_spaceid = arr[2];
		var src = arr[3];
		if (src_spaceid) {
			src = src_spaceid + src;
		}
		
		var list = $('#t32-list tr.asm td.addr');
		for (var i = 0; i < list.length; i++){
			var $td = list.eq(i);
			var arr = re.exec($td.text());
			
			var dst_spaceid = arr[2];
			var dst = arr[3];
			if (dst_spaceid) {
				dst = dst_spaceid + dst;
			}
			
			if (dst && src == dst){
				if (getListMode() == "HLL")
					setListMode("MIX")
				var hdrHeight = $('#header').outerHeight();
				var trHeight = getListMode()=="ASM" ? 0 : $('#t32-list tr:first-child').height();
				var y = $td.offset().top - hdrHeight - trHeight;
				$('html, body').scrollTop(y);
				highlight($td.parent());
				return;
			}
		}
	}
}

function gotoHllLine(module, file, lineFrom, lineTo){
	var $target = null;
	var list = $('#t32-list tr.hll td.addr');

	if (!lineFrom || !file || !module)
		return;
	file = module + "\\" + file;

	for (var i = 0; i < list.length; i++){
		var $td = list.eq(i);
		var dstLine = $td.text();
		var dstFile = $td.parent().data("module");
		if (dstLine == lineFrom  &&  dstFile == file){
			$target = $td;
			break;
		}
	}
	if (!$target && lineTo){
		for (var i = 0; i < list.length; i++){
			var $td = list.eq(i);
			var dstLine = $td.text();
			var dstFile = $td.parent().data("module");
			if (dstLine > lineFrom && dstLine <= lineTo &&  dstFile == file){
				$target = $td;
				break;
			}
		}
	}
	if ($target){
		var hdrHeight = $('#header').outerHeight();
		var trHeight = getListMode()=="HLL" ? 0 : $('#t32-list tr:first-child').height();
		if (getListMode() == "ASM")
			setListMode("MIX")
		var y = $target.offset().top - hdrHeight - 0.6*trHeight;
		$('html, body').scrollTop(y);
		highlight($target.parent());
	}
}

function linkcheck(evt){
	var href = $(this).attr('href');
	$.ajax({
		type: 'HEAD',
		url: href,
		context: $(this),
		success: function() {
			// page exists => open page
			var href = $(this).attr('href');
			window.location.href = href;
			// window.open(href, "_self");
		},
		error: function() {
			// page does not exist
			// In a perfect world we could remove the link now
			// However if Chrome or Opera (>=15) was started without "--allow-file-access-from-files" they will always return every ajax request on local files with error code 404

			// Check first if our own HTML page can be fetched via AJAX
			$.ajax({
				type: 'HEAD',
				url: window.location.href,
				context: $(this),
				success: function() {
					// We do exist. So just the link was bad => remove the link
					$(this).parent().html($(this).parent().text());
				},
				error: function() {
					// Chrome claims that we don't exist, so just open the requested link
					var href = $(this).attr('href');
					window.location.href = href;
				}
			});
		}
	});
	return false;
}

function fixFunctionNames($element){
	$element.each(function(){
		var text = $(this).text().split('\\')
		text = text.filter(String);
		$(this).text(text[2])
	});
}

function toggleDecisions() {
	if(showDecisions == false) {
		$(".dec").show();
		showDecisions = true;
	} else {
		$(".dec").hide();
		showDecisions = false;
	}
}

$(document).ready(function(){
	fixOldIE();

	/* improve footer: */
	$('#footer').append(
		'<form id="cb" action="">'+
			'<label for="cb1">color</label><input id="cb1" type="checkbox" checked="checked">'+
		'</form>'
	);
	$('#footer #cb1').change(updateColorMode); // Bind event handler

	var color = GetParam("color").toLowerCase();
	switch (color) {
		case "grey":
		case "gray":
			$('#cb1').removeProp("checked");
			$('body').addClass('gray');
			break;
		case "truewhite":
			$('body').addClass('truewhite');
			break;
	}

	/* pad adresses (and remove redundant prefixes) */
	beautifyAdresses();

	/* detect file extension of the current XML or HTML document */
	var ext = window.location.pathname.match(/\.[a-z]+$/i);
	gFileExt = ext ? ext[0] : ".html";

	/* improve main caption and add navigation */
	var root_rellative = ".";
	var navHtml = "";
	var modulePath = $('table.t32-coverage tr.module td.tree').first().text();
	var funcPath = $('table.t32-coverage tr.function td.tree').first().text();
	var funcName = funcPath.match(/[\w-]+$/);
	funcName = funcName ? funcName[0] : funcPath;
	var moduleName = modulePath.match(/[^\\]+$/);
	moduleName = moduleName ? moduleName[0] : modulePath;
	if ($('#t32-ListFunc').length){
		$('#t32-ListFunc > h2').first().append('<span class="sYmbol"> &nbsp;' + modulePath + '</span>');
		root_rellative = "../..";
		navHtml = ' <a href="./index'+gFileExt+'">Module:&nbsp;' + moduleName +'</a>';
	}
	if ($('#t32-ListLine').length){
		var func = '<span class="sYmbol"> &nbsp;' + funcName + '</span>';
		$('#t32-ListLine > h2').first().append(func);
		$('#t32-list > h2').first().append(func);
		/* $('#t32-bookmarks > h2').first().append(" of " + func); */
		root_rellative = "../..";
		navHtml =  ' <a href="./index'+gFileExt+'">Module:&nbsp;' + moduleName +'</a>';
		navHtml += ' <a href="#">Function:&nbsp;' + funcName +'</a>';
	}
	if ($('#t32-ListModule').length && $('#t32-list').length){ /* export_asm_module ? */
		var module = '<span class="sYmbol"> &nbsp;' + modulePath + '</span>';
		$('#t32-ListModule > h2').first().append(module);
		$('#t32-list > h2').first().append(module);
		root_rellative = "../..";
		navHtml =  ' <a href="./index'+gFileExt+'">Module:&nbsp;' + moduleName +'</a>';
	}
	$('#header').prepend(
		'<div class="nav">'+
			'Navigation: <a href="' + root_rellative + '/index'+gFileExt+'">Application</a>' + navHtml +
		'</div>'
	);

	/* add and improve time of creation */
	$('#content h2').first().append('<div class="ts" title="time of creation">'+$('tbody[data-ts]',this).data("ts")+'</div>');
	$('.ts').each(function(){
		$(this).text( formatTimeStamp($(this).text()) );
	});
	$('#footer li>em:contains("Timestamp: ")').text("Time of creation: ");

	/* make header fixed and clone header to an invisible absolute dummy to ensure that body starts always after the header */
	$('#header').clone().attr("id","header-fixed").css({position:"fixed"}).prependTo('body'); /* add fixed header */
	$('#header').css({visibility:"hidden"}); /* make relative header invisible (optional) */

	/* make column caption 'tree' nicer */
	$('table#t32-ListModule th.tree').text("module");
	$('table#t32-ListFunc th.tree').text("function");
	$('table#t32-ListLine th.tree').text("file \\ line");

	/* move Bookmarks before COVerage.ListGroup (if both are there) */
	$("#t32-bookmarks").insertBefore($("#t32-ListGroup"));

	/* cut program and module name for functions */
	if ($('#filelist').length == 0)
		fixFunctionNames($('tr.function > td.tree'))

	/* and linkes to open the modules from the module overview and to open the functions of each module */
	addFileLinks();

	/* add linkchecker */
	$("table.t32-coverage td.tree > a").click(linkcheck);
	$("#t32-bookmarks a").click(linkcheck);

	if ($('#t32-list').length){ /* List.EXPORT was used ? */
		/* Improve/beautify Code Listings */
		ImproveDataList();

		/* add radio buttons to controll list-mode (HLL/MIX/ASM) */
		$('#footer').prepend(
			'<form id="mode" action="">'+
				'<input id="rb1" type="radio" name="listmode" value="ASM"><label for="rb1">ASM</label> '+
				'<input id="rb2" type="radio" name="listmode" value="MIX"><label for="rb2">Mixed</label> '+
				'<input id="rb3" type="radio" name="listmode" value="HLL"><label for="rb3">HLL</label> '+
			'</form>'
		);
		$('#footer :radio').change(updateListMode);
		var mode = GetParam("mode").toUpperCase();
		setListMode(mode);

		/* enable address links */
		$('body').addClass("haveList");
		$('#t32-ListLine tr.line td.addr').click(function(){
			gotoAddress($(this).text());
		});
		$('#t32-bookmarks td.addr').click(function(){
			gotoAddress($(this).text());
		});
		$('#t32-ListLine tr.line td.tree').click(function(){
			var module = $(this).parent().data("module");
			var txt = $(this).text();
			var re = /([^\\]+?) ?\\([0-9]+)--([0-9]+)/i;
			var src = re.exec(txt);
			if (!src)
				return;
			gotoHllLine(module, src[1], src[2], src[3]);
		});
		$('#t32-bookmarks td.line').click(function(){
			var module = $(this).parent().children('.sym').text().match(/^\\\\[^\\]+\\[^\\]+/);
			var file = $(this).parent().children('.src').text().match(/[^\\]+$/);
			var line = $(this).text();
			if (!module || !file || !line)
				return;
			gotoHllLine(module[0], file[0], line);
		});
		$('#t32-bookmarks td.remark').click(function(){
			var line = $(this).parent().children('.line').text();
			if (line){
				var addr = $(this).parent().children('.addr').text()
				gotoAddress(addr);
			} else {
				var module = $(this).parent().children('.sym').text().match(/^\\\\[^\\]+\\[^\\]+/)[0];
				var file = $(this).parent().children('.src').text().match(/[^\\]+$/)[0];
				gotoHllLine(module, file, line);
			}
		});
	}

	/* make bookmarks sortable */
	makeTableSortable($('#t32-bookmarks table'));

	/* set all main tables to the same minimum width (looks smoother) */
	var minwidth = $('table.t32-coverage').first().width();
	if (minwidth)
		$("table.t32-coverage, #t32-list table, #t32-bookmarks table").css("min-width", minwidth + "px");

	/* jump to anchor if specified item is not visible */
	/* (FireFox has problems with calling a page with anchor on XSLT created pages) */
	var Anchor = GetParam("anchor");
	gotoAnchor(Anchor);

	/* jump to address if specified */
	var address = GetParam("address").toUpperCase();
	gotoAddress(address);
});
