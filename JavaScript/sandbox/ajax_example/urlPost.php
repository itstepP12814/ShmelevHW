<?php 
/*Этот сценарий запрашивает не бразуер, а AJAX.*/
	if(isset($_POST['url'])){
		/*Соответственно, инструкция echo делает вывод не в бразуер, а в атрибут обьекта XMLHttpRequest.responseText*/
		echo file_get_contents("http://".SanitizeString($_POST['url']));/*Получаем содержимое страницы*/
	}

	function SanitizeString($var){
		$var = strip_tags($var);
		$var =  htmlentities($var);
		return stripslashes($var);
	}
?>