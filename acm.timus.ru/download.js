/*
 *
 * result = [];
$('.odd,.even').each(function (index, item) {
    result.push({ 
        id: $(item).find('.id a').text(),
        url: $(item).find('.id a').attr('href'),
        problem: $(item).find('.problem a').text(),
        contest: $(item).find('.problem a').attr('href').replace(/.*space=/, '').replace(/&.* /,''),
        result: $(item).find('.verdict_rj,.verdict_ac').text()
    });

});
    console.log(JSON.stringify(result));
    */
var problems = require('./problem.json');

var request = require('request');
var fs = require('fs');
var Q = require('q');

//problems = [{"id":"6864539","url":"getsubmit.aspx/6864539.cpp","problem":"2068. Gam'e\" of Nuts","contest":"1","result":"Accepted"}];

requests = [];
var download = function (problem) {
    var deferred = Q.defer();
    var dirName = problem.problem.replace(/["'\?]/g, '');
    if (problem.content > 1) {
        dirName = 'Content_' + problem.content + '_' + dirName;
    }
    try {
        fs.mkdirSync(dirName);
    } catch (err) {
        // ignore
    }
    var result = problem.result.replace(' ', '_');
    var fileName = result + '_' + problem.url.replace(/.*\//, '');
    var file = fs.createWriteStream(dirName + '/' + fileName);

    var downloadRequest = request.post('http://acm.timus.ru/' + problem.url, {
        timeout: 10000,
        form:{
            JudgeID: '', // judgeid
            Password: '', // password
            Action: 'getsubmit'
        }
    });
    console.log('START: ' + dirName + '/' + fileName);
    downloadRequest.on('response', function (response) {
        console.log('DONE: ' + dirName + '/' + fileName);
        response.pipe(file);
        deferred.resolve();
    }).on('error', function () {
        console.log('FAIL: ' + dirName + '/' + fileName);
        deferred.reject();
    });
    return deferred.promise;
};

var index = 0;

var downloadsAll = function () {
    if (index < problems.length) {
        download(problems[index]).then(function () {
            index += 1;
            downloadsAll();
        }, function () {
            downloadsAll();
        });
    }
};

downloadsAll();




