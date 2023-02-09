var aabrham = angular.module('aabrham', []);

aabrham.controller('HomepageController', function HomepageController($scope, $http) {
    $scope.signout = function(){
        $http.get("/homepage/api/signout").then(function (result) {
            result.data.result ?
                window.location.href = "/" :
                $scope.failedLogin = true;
        });
    }
});